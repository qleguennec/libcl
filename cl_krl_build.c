/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_krl_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 22:17:19 by qle-guen          #+#    #+#             */
/*   Updated: 2016/12/09 16:10:22 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"
#include "../libft/libft.h"
#define GNL_BUFSIZ 80
#include "../libgnl/libgnl.h"
#include <unistd.h>
#include <stdio.h>

#define LOG_BUFSIZ 20480

cl_kernel
	cl_krl_build
	(t_cl_info *cl
	, int fd
	, char *krlname
	, size_t alloc_size)
{
	char		buffer[LOG_BUFSIZ];
	cl_kernel	krl;
	int			err;
	t_vect		lines;

	BZERO(lines);
	gnl_lines(fd, &lines, GNL_APPEND_CHAR);
	cl->prog = clCreateProgramWithSource(cl->ctxt
		, lines.used / sizeof(void *)
		, (const char **)lines.data, NULL, NULL);
	free(lines.data);
	if ((err = clBuildProgram(cl->prog
		, cl->dev_num, &cl->dev_id, "-Werror", NULL, NULL)) < 0)
	{
		clGetProgramBuildInfo(cl->prog, cl->dev_id, CL_PROGRAM_BUILD_LOG
			, LOG_BUFSIZ, buffer, NULL);
		write(1, buffer, ft_strlen(buffer));
		return (NULL);
	}
	if (!(krl = clCreateKernel(cl->prog, krlname, &err)))
		return (NULL);
	cl->mem = clCreateBuffer(cl->ctxt, 0, alloc_size, NULL, NULL);
	return (krl);
}
