/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 01:14:42 by qle-guen          #+#    #+#             */
/*   Updated: 2017/01/20 14:05:29 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"

cl_int
cl_write
	(t_cl_info *cl
	 , t_cl_krl *krl
	 , size_t narg
	 , void *data)
{
	return (clEnqueueWriteBuffer(cl->cmd_queue
		, krl->args[narg]
		, CL_TRUE
		, 0
		, krl->sizes[narg]
		, data
		, 0
		, NULL
		, NULL));
}
