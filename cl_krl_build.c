/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_krl_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 22:17:19 by qle-guen          #+#    #+#             */
/*   Updated: 2017/01/23 16:09:31 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/malloc.h"
#include "../libgnl/libgnl.h"
#include "libcl.h"
#include <unistd.h>

#define LOG_BUFSIZ 20480

static void
	krl_set_args
	(cl_context ctxt
	, t_cl_krl *krl)
{
	size_t		i;

	i = 0;
	while (i < krl->nargs)
	{
		krl->args[i] = clCreateBuffer(ctxt, 0, krl->sizes[i], NULL, NULL);
		CL_KRL_ARG(krl->krl, i, krl->args[i]);
		i++;
	}
}

static void
	krl_get_opts
	(char *line
	, char **krlname
	, char **opts)
{
	char	**split;

	split = (char **)STRSPLIT(line, ":");
	*krlname = split[0];
	*opts = split[1];
}

static void
	krl_source_free
	(t_vect lines
	, char *krlname
	, char *opts)
{
	size_t	i;

	free(krlname);
	free(opts);
	i = 0;
	while (i < lines.used / 8)
	{
		free(((char **)lines.data)[i]);
		i++;
	}
}

cl_int
	cl_krl_build
	(t_cl_info *cl
	, t_cl_krl *krl
	, int fd
	, char *optline)
{
	char		*krlname;
	char		*opts;
	char		buffer[LOG_BUFSIZ];
	cl_int		err;
	t_vect		lines;

	krl_get_opts(optline, &krlname, &opts);
	vect_init(&lines);
	gnl_lines(fd, &lines, GNL_APPEND_CHAR);
	cl->prog = clCreateProgramWithSource(cl->ctxt
		, lines.used / sizeof(void *)
		, (const char **)lines.data, NULL, NULL);
	if ((err = clBuildProgram(cl->prog
		, cl->dev_num, &cl->dev_id, opts, NULL, NULL)) < 0)
	{
		clGetProgramBuildInfo(cl->prog, cl->dev_id, CL_PROGRAM_BUILD_LOG
			, LOG_BUFSIZ, buffer, NULL);
		write(1, buffer, ft_strlen(buffer));
		return (err);
	}
	if (!(krl->krl = clCreateKernel(cl->prog, krlname, &err)))
		return (err);
	krl_source_free(lines, krlname, opts);
	krl_set_args(cl->ctxt, krl);
	return (CL_SUCCESS);
}
