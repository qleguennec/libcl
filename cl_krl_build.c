/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_krl_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 22:17:19 by qle-guen          #+#    #+#             */
/*   Updated: 2017/01/20 15:37:56 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../libft/malloc.h"
#include "../libgnl/libgnl.h"
#include "libcl.h"
#include <unistd.h>

#define LOG_BUFSIZ 20480

static void
	krl_setargs
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
	krl_source_free
	(t_vect lines)
{
	size_t	i;

	i = 0;
	while (i < lines.used / 8)
	{
		free(((char **)lines.data)[i]);
		i++;
	}
}

int
	cl_krl_build
	(t_cl_info *cl
	, t_cl_krl *krl
	, int fd
	, char *krlname)
{
	char		buffer[LOG_BUFSIZ];
	int			err;
	t_vect		lines;

	vect_init(&lines);
	gnl_lines(fd, &lines, GNL_APPEND_CHAR);
	cl->prog = clCreateProgramWithSource(cl->ctxt
		, lines.used / sizeof(void *)
		, (const char **)lines.data, NULL, NULL);
	krl_source_free(lines);
	if ((err = clBuildProgram(cl->prog
		, cl->dev_num, &cl->dev_id, "-Werror", NULL, NULL)) < 0)
	{
		clGetProgramBuildInfo(cl->prog, cl->dev_id, CL_PROGRAM_BUILD_LOG
			, LOG_BUFSIZ, buffer, NULL);
		write(1, buffer, ft_strlen(buffer));
		return (0);
	}
	if (!(krl->krl = clCreateKernel(cl->prog, krlname, &err)))
		return (0);
	krl_setargs(cl->ctxt, krl);
	return (1);
}
