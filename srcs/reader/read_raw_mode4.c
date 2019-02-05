/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_raw_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:22:18 by schakor           #+#    #+#             */
/*   Updated: 2018/11/22 17:13:20 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

static void				init_reader(t_shell *sh)
{
	if (!(sh->in = (t_input *)malloc(sizeof(*sh->in))))
		fatal_exit(sh, SH_ENOMEM);
	if (!(sh->in->buffer = (char *)malloc(sizeof(*sh->in->buffer) * BUF_TMP)))
		fatal_exit(sh, SH_ENOMEM);
	ft_memset(sh->in->buffer, '\0', BUF_TMP);
	sh->in->buf_i = 0;
	sh->in->bufsize = 0;
	sh->in->buftmp = BUF_TMP;
}

void					read_raw_mode(t_shell *sh)
{
	init_reader(sh);
	while (!(sh->key = 0))
	{
		if (read(STDIN_FILENO, &sh->key, 4) < 0)
			break ;
		if (ft_isprint(sh->key))
			insert_buffer(sh, (char)sh->key);
		else if (sh->key == LEFT_KEY)
			move_left_cursor(sh, &(sh->in->buf_i));
		else if (sh->key == RIGHT_KEY)
			move_right_cursor(sh, &(sh->in->buf_i));
		else if (sh->key == DELETE_KEY)
			delete_buffer(sh);
		else if (sh->key == UP_KEY)
			up_history(sh);
		else if (sh->key == DOWN_KEY)
			down_history(sh);
		else if (sh->key == ENTER_KEY)
		{
			sh->history_save = -2;
			break ;
		}
		if (sh->in->bufsize >= sh->in->buftmp)
			increase_buffer(sh);
	}
}
