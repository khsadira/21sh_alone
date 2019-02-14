/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exclaim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 14:32:04 by khsadira          #+#    #+#             */
/*   Updated: 2019/02/08 18:53:05 by khsadira         ###   ########.fr       */
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
	tmp = ft_memfreejoin(&tmp, sh->history->buffer, var.tmpsize, sh->history->bufsize);
	var.tmpsize += sh->history->bufsize;
	return (tmp);
}

static int				looking_for_similar(char *s1, t_history *hist, size_t i, size_t j)
{
	size_t	taille;
	size_t	k;

	k = 0;
	printf("%zu\n", hist->bufsize);
	ft_putendl(hist->buffer);
	printf("%zu | %zu\n", j, i);
	ft_putendl(s1);
	taille = j - i;
	while (k < hist->bufsize && i < j)
	{
		if (s1[i] != hist->buffer[k])
			return (0);
		k++;
		i++;
	}
	printf("%zu | %zu\n", k, hist->bufsize);
	if (k >= hist->bufsize)
		return (1);
	return (0);
}

static char				*replace_exclaim_two(t_shell *sh, size_t i, size_t j, char *tmp)
{
	t_history	*tmp_hist;

	i++;
	tmp_hist = sh->history;
	while (tmp_hist)
	{
		if (sh->in->buffer[i] == tmp_hist->buffer[0])
		{
			ft_putstr("here\n");
			move_start(sh);
			if (looking_for_similar(sh->in->buffer, tmp_hist, i, j))
			{
				ft_putstr("here2\n");
				tmp = ft_memfreejoin(&tmp, tmp_hist->buffer, var.tmpsize, tmp_hist->bufsize);
				var.tmpsize += tmp_hist->bufsize;
				return (tmp);
			}
		}
		tmp_hist = tmp_hist->bfr;
	}
	return (tmp);
}

static char				*replace_exclaim_three(t_shell *sh, size_t i, size_t j, char *tmp)
{
	size_t		nb;
	size_t		stock;
	size_t		start;
	t_history	*head;

	nb = 0;
	start = i + 1;
	stock = j - start;
	move_start(sh);
	while (stock--)
	{
		nb *= 10;
		nb += (int)(sh->in->buffer[start]) - 48;
		start++;
	}
//	if (nb > sh->history_size)
//		return ("ERREUR");
	head = sh->history;
	while (sh->history->bfr)
		sh->history = sh->history->bfr;
	while (--nb)
		sh->history = sh->history->next;
	tmp = ft_memfreejoin(&tmp, sh->history->buffer, var.tmpsize, sh->history->bufsize);
	var.tmpsize += sh->history->bufsize;
	sh->history = head;
	return (tmp);
}

static char				*ft_memfreejoin(char **s1, char *s2, size_t bufsize, size_t tmpsize)
{
	char	*tmp;

	tmp = NULL;
	if (!(tmp = (char *)malloc(sizeof(char) * (bufsize + tmpsize))))
		return (NULL);
	ft_memcpy(tmp, *s1, bufsize);
	ft_memcpy(tmp + bufsize, s2, tmpsize);
	if (bufsize > 0)
		free(*s1);
	return (tmp);
}

static char				*replace_exclaim(t_shell *sh, size_t i, size_t j, char *tmp)
{
	return NULL;
	if (var.exclaim_type == 1)
		tmp = replace_exclaim_one(sh, tmp);
	else if (var.exclaim_type == 2)
		tmp = replace_exclaim_two(sh, i, j, tmp);
	else if (var.exclaim_type == 3)
		tmp = replace_exclaim_three(sh, i, j, tmp);
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
		move_start(sh);
		i = j;
		while (i < sh->in->bufsize && sh->in->buffer[i] != '!')
			i++;
//		if (!(i < sh->in->bufsize))
//			break;
		j = end_of_exclaim(i, j, &tmp, sh);
		tmp = replace_exclaim(sh, i, j, tmp);
		if (var.tmpsize > 0)
		{
			buff = ft_memfreejoin(&buff, tmp, var.bufsize, var.tmpsize);
			var.bufsize += var.tmpsize;
		}
		var.tmpsize = 0;
		var.exclaim_type = 0;
	}
	move_start(sh);
	sh->in->buffer = buff;
	sh->in->bufsize = var.bufsize;
	ft_putendl(buff);
}
