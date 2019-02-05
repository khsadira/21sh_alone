/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:05:18 by schakor           #+#    #+#             */
/*   Updated: 2017/11/30 17:31:16 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cptr1;
	unsigned char	*cptr2;

	cptr1 = (unsigned char *)s1;
	cptr2 = (unsigned char *)s2;
	while (n--)
	{
		if (*cptr1 != *cptr2)
			return (*cptr1 - *cptr2);
		++cptr1;
		++cptr2;
	}
	return (0);
}
