/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 15:18:43 by qle-guen          #+#    #+#             */
/*   Updated: 2016/12/08 15:32:55 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

void
cl_init
	(t_cl_info *cl)
{
	clGetPlatformIDs(1, &cl->pl_id, NULL);
	clGetDeviceIDs(cl->pl_id
		, CL_DEVICE_TYPE_GPU, 1, &cl->dev_id, &cl->dev_num);
	cl->ctxt = clCreateContext(NULL, 1, &cl->dev_id, NULL, NULL, NULL);
	cl->cmd_queue = clCreateCommandQueue(cl->ctxt, cl->dev_id, 0, NULL);
}
