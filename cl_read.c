/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 02:17:46 by qle-guen          #+#    #+#             */
/*   Updated: 2016/12/14 16:25:25 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

void
	cl_read
	(t_cl_info *cl
	, t_cl_krl *krl
	, size_t narg
	, void *data)
{
	clFinish(cl->cmd_queue);
	clEnqueueReadBuffer(cl->cmd_queue
		, krl->args[narg]
		, CL_TRUE
		, 0
		, krl->sizes[narg]
		, data
		, 0
		, NULL
		, NULL);
}
