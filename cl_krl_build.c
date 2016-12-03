/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_krl_build.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 22:17:19 by qle-guen          #+#    #+#             */
/*   Updated: 2016/12/03 01:14:36 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"
#include "../libft/libft.h"
#include <unistd.h>

cl_kernel
cl_krl_build
	(t_cl_info *cl
	 , int fd
	 , char *krlname
	 , size_t alloc_size)
{
	char		buffer[CL_BUFSIZ + 1];
	cl_kernel	krl;
	size_t		i;

	i = read(fd, buffer, CL_BUFSIZ);
	buffer[i] = '\0';
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
