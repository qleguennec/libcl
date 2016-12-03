/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 18:24:58 by qle-guen          #+#    #+#             */
/*   Updated: 2016/12/03 02:22:58 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CL_HELPER_H
# define CL_HELPER_H

# include <CL/opencl.h>

# ifndef CL_BUFSIZ
#  define CL_BUFSIZ 20480
# endif

# define CL_KRL_ARG(k, i, a) clSetKernelArg(k, i, sizeof(a), &a)

typedef struct			s_cl_info
{
	cl_platform_id		pl_id;
	cl_device_id		dev_id;
	cl_context			ctxt;
	cl_command_queue	cmd_queue;
	cl_program			prog;
	cl_uint				dev_num;
	cl_mem				mem;
}						t_cl_info;

cl_event				*cl_krl_exec(t_cl_info *cl, cl_kernel krl, cl_uint work_dim, size_t *work_size);
cl_kernel				cl_krl_build(t_cl_info *cl, int fd, char *krlname, size_t alloc_size);
void					cl_init(t_cl_info *cl, void *data, size_t data_size);
void					cl_write(t_cl_info *cl, size_t offset, void *data, size_t size);
void					cl_read(t_cl_info *cl, cl_event *ev, void *data, size_t size);

#endif
