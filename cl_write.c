/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 01:14:42 by qle-guen          #+#    #+#             */
/*   Updated: 2016/12/03 01:18:50 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

void
cl_write
	(t_cl_info *cl
	 , size_t offset
	 , void *data
	 , size_t size)
{
	clEnqueueWriteBuffer(cl->cmd_queue
		, cl->mem, CL_TRUE, offset, size, data, 0, NULL, NULL);
}
