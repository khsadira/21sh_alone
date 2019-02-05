/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 10:19:31 by schakor           #+#    #+#             */
/*   Updated: 2017/11/16 15:45:24 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*cptr;

	cptr = dst;
	while (*src != '\0' && n > 0)
	{
		*cptr = *src;
		++cptr;
		++src;
		--n;
	}
	while (n--)
	{
		*cptr = '\0';
		++cptr;
	}
	return (dst);
}
