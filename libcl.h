/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcl.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/11 18:24:58 by qle-guen          #+#    #+#             */
/*   Updated: 2016/12/02 23:20:24 by qle-guen         ###   ########.fr       */
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
	cl_mem				mem;
	cl_program			prog;
	cl_kernel			kernel;
	cl_uint				dev_num;
}						t_cl_info;

cl_kernel				cl_prg_read(t_cl_info *cl, char *prgname, char *krlname);
void					cl_init(t_cl_info *cl, void *data, size_t data_size);

#endif
