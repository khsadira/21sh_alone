/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:34:03 by schakor           #+#    #+#             */
/*   Updated: 2017/11/29 07:49:58 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*cptr1;
	unsigned char	*cptr2;

	cptr1 = (unsigned char *)s1;
	cptr2 = (unsigned char *)s2;
	while (n--)
	{
		if (*cptr1 != *cptr2 || *cptr1 == '\0' || *cptr2 == '\0')
			return (*cptr1 - *cptr2);
		++cptr1;
		++cptr2;
	}
	return (0);
}
