/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 22:37:56 by schakor           #+#    #+#             */
/*   Updated: 2018/11/14 17:44:36 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void			move_start(t_shell *sh)
{
	size_t		index;

	index = sh->in->buf_i + sh->len_prompt;
	while (index > 0)
	{
		ft_putstr(tgetstr("le", NULL));
		index--;
	}
}

void			move_left_cursor(t_shell *sh, size_t *index)
{
	(void)sh;
	if (*index > 0)
	{
		ft_putstr(tgetstr("le", NULL));
		(*index)--;
	}
}

void			move_right_cursor(t_shell *sh, size_t *index)
{
	struct winsize w;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &w);
	if (*index < sh->in->bufsize)
	{
		if (*index != 0 && ((*index + sh->len_prompt + 1) % w.ws_col == 0))
		{
			ft_putstr(tgetstr("cr", NULL));
			ft_putstr(tgetstr("do", NULL));
		}
		else
			ft_putstr(tgetstr("nd", NULL));
		(*index)++;
	}
}

void			move_end(t_shell *sh)
{
	size_t			i;

	i = sh->in->buf_i;
	while (i < sh->in->bufsize)
		move_right_cursor(sh, &i);
}
