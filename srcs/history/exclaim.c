/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exclaim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:32:04 by khsadira          #+#    #+#             */
/*   Updated: 2019/02/05 14:32:29 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

typedef struct	s_var
{
	size_t	bufsize;
	size_t	tmpsize;
	size_t	exclaim_type;
}			t_var;

static char				*ft_memfreejoin(char **over, char *buff, size_t bufsize, size_t tmpsize);
static t_var	var;

static void				ft_memidel(char *buff, size_t size)
{
	while (size--)
		ft_memdel((void **)buff++);
}

static t_var			init_var(t_var var)
{
	var.bufsize = 0;
	var.tmpsize = 0;
	var.exclaim_type = 0;
	return (var);
}

static size_t			end_of_exclaim(size_t i, size_t j, char **tmp, t_shell *sh)
{
	if (i + 1 >= sh->in->bufsize)
		return (-1);
	if (i != j)
	{
		*tmp = ft_memalloc(i - j);
		*tmp = ft_memcpy(*tmp, sh->in->buffer + j, j - i);
	}
	j = i + 1;
	if (sh->in->buffer[j] == '!')
	{
		j++;
		var.exclaim_type = 1;
	}
	else if (ft_isalpha(sh->in->buffer[j]))
	{
		while (j < sh->in->bufsize && ft_isalnum(sh->in->buffer[j]))
			j++;
		var.exclaim_type = 2;
	}
	else if	(ft_isdigit(sh->in->buffer[j]))
	{
		while (j < sh->in->bufsize && ft_isdigit(sh->in->buffer[j]))
			j++;
		var.exclaim_type = 3;
	}
	return (j);
}

static char				*replace_exclaim_one(t_shell *sh, char *tmp)
{
	char	*buf;

	buf = ft_memalloc(sh->history->bufsize);
	move_start(sh);
	buf = ft_memcpy(buf, sh->history->buffer, sh->history->bufsize);
	var.tmpsize = sh->history->bufsize;
	tmp = ft_memfreejoin(&tmp, buf, var.bufsize, var.tmpsize);
	return (tmp);
}

static void				replace_exclaim_two(t_shell *sh, size_t i, size_t j, char **tmp)
{
	(void)sh;
	i++;
	j++;
	(void)tmp;
}

static void				replace_exclaim_three(t_shell *sh, size_t i, size_t j, char **tmp)
{
	(void)sh;
	i++;
	j++;
	(void)tmp;
}

static char				*ft_memfreejoin(char **s1, char *s2, size_t bufsize, size_t tmpsize)
{
	char	*tmp;

	tmp = NULL;
	if (!(tmp = (char *)malloc(sizeof(char) * (bufsize + tmpsize))))
		return (NULL);
	ft_memcpy(tmp, *s1, bufsize);
	ft_memcpy(tmp + bufsize, s2, tmpsize);
	ft_memidel(*s1, var.bufsize);
	return (tmp);
}

static char				*replace_exclaim(t_shell *sh, size_t i, size_t j, char *tmp)
{
	if (var.exclaim_type == 1)
		tmp = replace_exclaim_one(sh, tmp);
	else if (var.exclaim_type == 2)
		replace_exclaim_two(sh, i, j, &tmp);
	else if (var.exclaim_type == 3)
		replace_exclaim_three(sh, i, j, &tmp);
	return (tmp);
}

void					exclaim(t_shell *sh)
{
	char	*tmp;
	size_t	i;
	size_t	j;
	char	*buff;

	i = 0;
	j = 0;
	var = init_var(var);
	while (i < sh->in->bufsize && j < sh->in->bufsize)
	{
		move_start(sh);
		ft_putstr("here\n");
		move_start(sh);
		i = j;
		while (i < sh->in->bufsize && sh->in->buffer[i] != '!')
			i++;
//		if (!(i < sh->in->bufsize))
//			break;
		j = end_of_exclaim(i, j, &tmp, sh);
		move_start(sh);
		tmp = replace_exclaim(sh, i, j, tmp);
		buff = ft_memfreejoin(&buff, tmp, var.bufsize, var.tmpsize);
		var.bufsize += var.tmpsize;
		ft_memidel(tmp, var.tmpsize);
		var.tmpsize = 0;
	}
	move_start(sh);
	sh->in->buffer = buff;
	sh->in->bufsize = var.bufsize;
	ft_putendl(buff);
}
