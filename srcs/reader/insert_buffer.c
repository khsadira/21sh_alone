/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_buffer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 21:54:11 by schakor           #+#    #+#             */
/*   Updated: 2018/11/12 14:38:19 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

void			insert_buffer(t_shell *sh, char c)
{
	size_t		i;

	i = sh->in->bufsize;
	ft_memmove(sh->in->buffer + sh->in->buf_i + 1, sh->in->buffer\
			+ sh->in->buf_i, i - sh->in->buf_i);
	sh->in->buffer[sh->in->buf_i] = c;
	move_start(sh);
	ft_putstr(tgetstr("cd", NULL));
	display_prompt(sh);
	sh->in->bufsize++;
	write(1, sh->in->buffer, sh->in->bufsize);
	i = sh->in->bufsize;
	sh->in->buf_i++;
	while (i > sh->in->buf_i)
		move_left_cursor(sh, &i);
}

void			delete_buffer(t_shell *sh)
{
	size_t		i;

	if (sh->in->buf_i < 1)
		return ;
	ft_memcpy(sh->in->buffer + sh->in->buf_i - 1, sh->in->buffer +\
			sh->in->buf_i, sh->in->bufsize - sh->in->buf_i + 1);
	move_start(sh);
	ft_putstr(tgetstr("cd", NULL));
	display_prompt(sh);
	sh->in->bufsize--;
	write(1, sh->in->buffer, sh->in->bufsize);
	i = sh->in->bufsize;
	sh->in->buf_i--;
	while (i > sh->in->buf_i)
		move_left_cursor(sh, &i);
}
