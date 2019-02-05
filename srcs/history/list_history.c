/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_histori.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 11:28:39 by khsadira          #+#    #+#             */
/*   Updated: 2018/11/28 11:38:41 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

t_history	*new_hist(char *buffer, size_t bufsize, size_t buftmp)
{
	t_history	*list;

	if (!(list = (t_history *)malloc(sizeof(*list))))
		return (NULL);
	if (!(list->buffer = (char *)ft_memalloc(buftmp)))
		return (NULL);
	ft_memcpy(list->buffer, buffer, bufsize);
	list->bufsize = bufsize;
	list->buftmp = buftmp;
	list->next = NULL;
	list->bfr = NULL;
	return (list);
}

t_history	*add_hist(t_history *list, t_history *new_hist)
{
	if (new_hist == NULL)
	{
		while (list && list->next)
			list = list->next;
		return (list);
	}
	if (list == NULL)
		return (new_hist);
	while (list->next)
		list = list->next;
	list->next = new_hist;
	new_hist->bfr = list;
	return (new_hist);
}
