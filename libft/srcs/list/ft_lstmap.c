/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 09:02:52 by schakor           #+#    #+#             */
/*   Updated: 2017/12/06 10:30:05 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*head;
	t_list	*new;

	if (!f || !lst)
		return (NULL);
	if (!(new = (*f)(ft_lstnew(lst->content, lst->content_size))))
		return (NULL);
	head = new;
	while (lst->next)
	{
		new->next =
			(*f)(ft_lstnew(lst->next->content, lst->next->content_size));
		if (new->next == NULL)
			return (NULL);
		lst = lst->next;
		new = new->next;
	}
	return (head);
}
