/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:29:22 by schakor           #+#    #+#             */
/*   Updated: 2018/11/19 11:30:54 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

static void				init_env_var(t_shell *sh, char **env)
{
	sh->env = ft_arrdup(env);
	sh->envl = envarr_2_envl(env);
}

t_shell					*init_shell(int ac, char **av, char **env)
{
	t_shell		*sh;

	(void)ac;
	(void)av;
	if (!(sh = (t_shell *)malloc(sizeof(*sh))))
		fatal_exit(sh, SH_ENOMEM);
	init_env_var(sh, env);
	sh->key = 0;
	sh->len_prompt = 0;
	sh->in = NULL;
	sh->tk = NULL;
	sh->root = NULL;
	init_terminal(sh);
	sh->history = NULL;
	sh->history_save = -2;
	history_from_file(sh, get_env_val(sh->envl, "HOME"));
	return (sh);
}
