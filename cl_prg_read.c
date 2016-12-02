/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_prg_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 22:17:19 by qle-guen          #+#    #+#             */
/*   Updated: 2016/12/02 23:17:08 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <unistd.h>

cl_kernel
cl_prg_read
	(t_cl_info *cl
	 , char *prgname
	 , char *krlname)
{
	char	buffer[CL_BUFSIZ + 1];
	int		fd;
	size_t	i;

	if ((fd = open(prgname, O_RDONLY)) == -1)
		return (NULL);
	i = read(fd, buffer, CL_BUFSIZ);
	close(fd);
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
	return (clCreateKernel(cl->prog, krlname, NULL));
}
