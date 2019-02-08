/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:37:05 by khsadira          #+#    #+#             */
/*   Updated: 2019/02/08 17:05:13 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

int			main(int ac, char **av, char **env)
{
	t_shell		*sh;

	sh = init_shell(ac, av, env);
	while (42)
	{
		signal(SIGINT, ft_signal);
		//signal(SIGSEGV, ft_signal);
		//signal(SIGABRT, ft_signal);
		display_prompt(sh);
		read_raw_mode(sh);
		//lexer(sh);
		//parser(sh);
		write(1, "\n", 1);
		ft_putstr(tgetstr("cr", NULL));
		ft_putstr(sh->in->buffer);
		if (ft_strchr(sh->in->buffer, '!'))
			exclaim(sh);
		add_history(sh);
		if (ft_strequ(sh->in->buffer, "exit"))
		{
			reset_terminal();
			file_from_history(sh, get_env_val(sh->envl, "HOME"));
			exit(EXIT_FAILURE);
		}
		write(1, "\n", 1);
		ft_putstr(tgetstr("cr", NULL));
		free_input(sh->in);
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &(sh->cooked_tio));
	return (0);
}
