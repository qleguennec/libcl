/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_krl_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 02:06:54 by qle-guen          #+#    #+#             */
/*   Updated: 2016/12/03 02:11:55 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"
#include "../libft/malloc.h"

cl_event
*cl_krl_exec
	(t_cl_info *cl
	 , cl_kernel krl
	 , cl_uint work_dim
	 , size_t *work_size)
{
	cl_event	*ev;

	MALLOC1(ev);
	clEnqueueNDRangeKernel(cl->cmd_queue
		, krl, work_dim, NULL, work_size, NULL, 0, NULL, ev);
	return (ev);
}
