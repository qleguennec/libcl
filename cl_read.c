/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 02:17:46 by qle-guen          #+#    #+#             */
/*   Updated: 2016/12/14 14:24:19 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

void
	cl_read
	(t_cl_info *cl
	, void *data
	, size_t size)
{
	clFinish(cl->cmd_queue);
	clEnqueueReadBuffer(cl->cmd_queue
		, cl->mem, CL_TRUE, 0
		, size, data
		, 0
		, NULL
		, NULL);
}
