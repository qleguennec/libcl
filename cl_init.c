/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 15:18:43 by qle-guen          #+#    #+#             */
/*   Updated: 2016/12/03 02:46:04 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

void
cl_init
	(t_cl_info *cl
	 , size_t alloc_size)
{
	clGetPlatformIDs(1, &cl->pl_id, NULL);
	clGetDeviceIDs(cl->pl_id
		, CL_DEVICE_TYPE_GPU, 1, &cl->dev_id, &cl->dev_num);
	cl->ctxt = clCreateContext(NULL, 1, &cl->dev_id, NULL, NULL, NULL);
	cl->cmd_queue = clCreateCommandQueueWithProperties(cl->ctxt,
		cl->dev_id, NULL, NULL);
	cl->mem = clCreateBuffer(cl->ctxt
		, CL_MEM_READ_WRITE, alloc_size, NULL, NULL);
}
