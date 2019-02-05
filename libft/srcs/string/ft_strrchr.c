/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 13:02:01 by schakor           #+#    #+#             */
/*   Updated: 2017/11/29 10:26:45 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*end;

	end = (char*)s + ft_strlen(s);
	while (end >= (char*)s)
	{
		if (*end == (char)c)
			return ((char *)end);
		--end;
	}
	return (NULL);
}
