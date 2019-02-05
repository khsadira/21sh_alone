/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_raw_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:22:18 by schakor           #+#    #+#             */
/*   Updated: 2018/11/23 19:04:26 by schakor          ###   ########.fr       */
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
	ft_memset(sh->in->bufkey, 0, 8);
}

static int				check_key(t_shell *sh, t_uint8 key[8], int *i)
{
	if ((key[0] == 27 && key[1] == 91 && key[2] == 68) ||
		(key[0] == 27 && key[1] == 91 && key[2] == 67) ||
		(key[0] == 27 && key[1] == 91 && key[2] == 66) ||
		(key[0] == 27 && key[1] == 91 && key[2] == 65) ||
		(key[0] == 27 && key[1] == 91 && key[2] == 72) ||
		(key[0] == 27 && key[1] == 91 && key[2] == 70) ||
		(key[0] == 27 && key[1] == 91 && key[2] == 49 && key[3] == 59 && key[4] == 50 && key[5] == 68) ||
		(key[0] == 27 && key[1] == 91 && key[2] == 49 && key[3] == 59 && key[4] == 50 && key[5] == 67) ||
		(key[0] == 27 && key[1] == 91 && key[2] == 49 && key[3] == 59 && key[4] == 50 && key[5] == 66) ||
		(key[0] == 27 && key[1] == 91 && key[2] == 49 && key[3] == 59 && key[4] == 50 && key[5] == 65))
		return (2);
	if ((key[0] == 27 && key[1] == 0) || (key[0] == 27 && key[1] == 91 && key[2] == 0) ||
		(key[0] == 27 && key[1] == 91 && key[2] == 49 && key[3] == 0) ||
		(key[0] == 27 && key[1] == 91 && key[2] == 49 && key[3] == 59 && key[4] == 0))
		return (1);
	if (key[0] == 27)
	{
		ft_memset(sh->in->bufkey, 0, 8);
		*i = 0;
	}
	return (0);
}

void					read_raw_mode(t_shell *sh)
{
	t_uint8				key;
	int					i;
	int					ret;

	i = 0;
	init_reader(sh);
	while (42)
	{
		if (read(STDIN_FILENO, &key, 1) < 0)
			break ;
		sh->in->bufkey[i++] = key;
		ret = check_key(sh, sh->in->bufkey, &i);
		if (sh->in->bufkey[0] == 27 && (ret == 2 || ret == 1))
		{
			if (ret == 2)
			{

				if	(((long *)(sh->in->bufkey))[0] == LEFT_KEY)
					move_left_cursor(sh, &(sh->in->buf_i));
				else if (((long *)(sh->in->bufkey))[0] == RIGHT_KEY)
					move_right_cursor(sh, &(sh->in->buf_i));
				else if (((long *)(sh->in->bufkey))[0] == UP_KEY)
					up_history(sh);
				else if (((long *)(sh->in->bufkey))[0] == DOWN_KEY)
					down_history(sh);
				ft_memset(sh->in->bufkey, 0, 8);
				i = 0;
			}
		}
		else if (sh->in->bufkey[0])
		{
			if (sh->in->bufkey[0] == ENTER_KEY)
			{
				sh->history_save = -2;
				break;
			}
			else if (sh->in->bufkey[0] == DELETE_KEY)
				delete_buffer(sh);
			else
				insert_buffer(sh, (char)sh->in->bufkey[0]);
			i = 0;
			ft_memset(sh->in->bufkey, 0, 8);
		}
		if (sh->in->bufsize >= sh->in->buftmp)
			increase_buffer(sh);
	}
}
