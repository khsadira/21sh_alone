/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:48:23 by schakor           #+#    #+#             */
/*   Updated: 2018/11/14 16:51:19 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void		fatal_exit(t_shell *sh, int code)
{
	if (sh)
		free_term(sh);
	if (code == SH_ENOMEM)
		ft_putendl_fd("Cannot allocate memory.\n", STDERR_FILENO);
	else if (code == SH_EINVAL)
		ft_putendl_fd("Invalid argument.\n", STDERR_FILENO);
	else if (code == SH_ENOTTY)
		ft_putendl_fd("Inappropriate ioctl device.\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
