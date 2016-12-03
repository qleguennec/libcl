/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 18:24:58 by qle-guen          #+#    #+#             */
/*   Updated: 2016/12/03 00:31:59 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CL_HELPER_H
# define CL_HELPER_H

# include <CL/opencl.h>

# ifndef CL_BUFSIZ
#  define CL_BUFSIZ 20480
# endif

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

cl_kernel				cl_krl_build(t_cl_info *cl, int fd, char *krlname, size_t alloc_size);
void					cl_init(t_cl_info *cl, void *data, size_t data_size);

#endif
