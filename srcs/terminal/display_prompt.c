/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 23:03:00 by schakor           #+#    #+#             */
/*   Updated: 2018/11/12 14:16:44 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void		display_prompt(t_shell *sh)
{
	char	*cwd;
	char	buff[4097];
	int		i;
	int		len;
	char	*tmp;

	tmp = NULL;
	if ((cwd = getcwd(buff, 4096)))
	{
		len = ft_strlen(cwd);
		i = len;
		while (i > 0 && cwd[i] != '/')
			i--;
		if (cwd[i] == '/' && ft_strlen(cwd) != 1)
			i++;
		tmp = ft_strsub(cwd, i, len - i);
	}
	ft_putstr("\033[0;31m");
	ft_putstr("<");
	if (tmp)
	ft_putstr(tmp);
	ft_putstr("> ");
	ft_putstr("\033[0m");
	sh->len_prompt = ft_strlen(tmp) + 3;
	ft_strdel(&tmp);
}
