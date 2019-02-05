/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:40:51 by schakor           #+#    #+#             */
/*   Updated: 2017/11/16 14:56:16 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*n)
		return (char *)h;
	i = 0;
	while (h[i] && i < len)
	{
		j = 0;
		while (h[i + j] == n[j] && n[j] && i + j < len)
			++j;
		if (!n[j])
			return (char *)(h + i);
		++i;
	}
	return (NULL);
}
