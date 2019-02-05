/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_raw_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 20:22:18 by schakor           #+#    #+#             */
/*   Updated: 2018/11/22 18:13:54 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

static void				init_reader(t_shell *sh)
{
	if (!(sh->in = (t_input *)malloc(sizeof(*sh->in))))
	{
		free(sh);
		ft_putendl_fd("Cannot allocate memory.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (!(sh->in->buffer = (char *)malloc(sizeof(*sh->in->buffer) * BUF_TMP)))
	{
		free(sh->in);
		free(sh);
		ft_putendl_fd("Cannot allocate memory.", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_memset(sh->in->buffer, '\0', BUF_TMP);
	sh->in->buf_i = 0;
	sh->in->bufsize = 0;
	sh->in->buftmp = BUF_TMP;
}

void					read_raw_mode(t_shell *sh)
{
	unsigned long long int	key;

	init_reader(sh);
	while (!(key = 0))
	{
		if (read(STDIN_FILENO, &key, 8) < 0)
			break ;
		printf("[%d] [%d] [%d] [%d] [%d] [%d] [%d] [%d]\n", ((unsigned char *)(&(key)))[0], ((unsigned char *)(&(key)))[1], ((unsigned char *)(&(key)))[2], ((unsigned char *)(&(key)))[3], ((unsigned char *)(&(key)))[4], ((unsigned char *)(&(key)))[5], ((unsigned char *)(&(key)))[6], ((unsigned char *)(&(key)))[7]);
		ft_putstr(tgetstr("cr", NULL));
		/*
		if (ft_isprint(key))
			insert_buffer(sh, (char)key);
		else if (key == LEFT_KEY)
			move_left_cursor(sh, &(sh->in->buf_i));
		else if (key == RIGHT_KEY)
			move_right_cursor(sh, &(sh->in->buf_i));
		else if (key == DELETE_KEY)
			delete_buffer(sh);
		else if (key == UP_KEY)
			up_history(sh);
		else if (key == DOWN_KEY)
			down_history(sh);
		else if (key == ENTER_KEY)
		{
			sh->history_save = -2;
			break ;
		}
		if (sh->in->bufsize >= sh->in->buftmp)
			increase_buffer(sh);
		*/
	}
}
