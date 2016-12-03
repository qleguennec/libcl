/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_krl_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 22:17:19 by qle-guen          #+#    #+#             */
/*   Updated: 2016/12/03 03:44:48 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"
#include "../libft/libft.h"
#include "../libgnl/libgnl.h"
#include <unistd.h>

cl_kernel
cl_krl_build
	(t_cl_info *cl
	 , int fd
	 , char *krlname
	 , size_t alloc_size)
{
	t_vect		buf;
	t_vect		line;
	t_vect		lines;
	cl_kernel	krl;

	vect_init(&buf);
	vect_init(&line);
	vect_init(&lines);
	while (get_next_line())
	cl->prog = clCreateProgramWithSource(cl->ctxt, 1
		, (const char **)&buffer, NULL, NULL);
	if (!clBuildProgram(cl->prog, cl->dev_num, &cl->dev_id, NULL, NULL, NULL))
	{
		clGetProgramBuildInfo(cl->prog, cl->dev_id, CL_PROGRAM_BUILD_LOG
			, CL_BUFSIZ, buffer, NULL);
		write(1, buffer, ft_strlen(buffer));
		return (NULL);
	}
	if (!(krl = clCreateKernel(cl->prog, krlname, NULL)))
		return (NULL);
	cl->mem = clCreateBuffer(cl->ctxt, 0, alloc_size, NULL, NULL);
	return (krl);
}
