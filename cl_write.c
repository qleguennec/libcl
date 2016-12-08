/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 01:14:42 by qle-guen          #+#    #+#             */
/*   Updated: 2016/12/08 15:27:18 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

cl_int
cl_write
	(t_cl_info *cl
	 , size_t offset
	 , void *data
	 , size_t size)
{
	return (clEnqueueWriteBuffer(cl->cmd_queue
		, cl->mem, CL_TRUE, offset, size, data, 0, NULL, NULL));
}
