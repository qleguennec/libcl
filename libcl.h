/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 18:24:58 by qle-guen          #+#    #+#             */
/*   Updated: 2017/01/25 12:00:43 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CL_HELPER_H
# define CL_HELPER_H

# include <OpenCL/opencl.h>

# define CL_KRL_ARG(k, i, a) clSetKernelArg(k, i, sizeof(a), (void*)&a)

typedef struct			s_cl_info
{
	cl_platform_id		pl_id;
	cl_device_id		dev_id;
	cl_context			ctxt;
	cl_command_queue	cmd_queue;
	cl_program			prog;
	cl_uint				dev_num;
}						t_cl_info;

typedef struct			s_cl_krl
{
	cl_kernel			krl;
	cl_mem				*args;
	size_t				*sizes;
	size_t				nargs;
}						t_cl_krl;

cl_int					cl_krl_build(t_cl_info *cl, t_cl_krl *krl, int fd, char *optline);
cl_int					cl_krl_exec(t_cl_info *cl, cl_kernel krl, cl_uint work_dim, size_t *work_size);
cl_int					cl_read(t_cl_info *cl, t_cl_krl *krl, size_t narg, void *data);
cl_int					cl_write(t_cl_info *cl, t_cl_krl *krl, size_t narg, void *data);
void					cl_init(t_cl_info *cl);
void					cl_krl_init(t_cl_krl *krl, size_t nargs);

#endif
