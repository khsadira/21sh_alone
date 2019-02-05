/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:37:37 by schakor           #+#    #+#             */
/*   Updated: 2017/12/06 10:47:03 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*ucptr1;
	char	*ucptr2;
	char	tmp;

	ucptr1 = (char *)dst;
	ucptr2 = (char *)src;
	tmp = (unsigned char)c;
	while (n--)
	{
		if ((*ucptr1++ = *ucptr2++) == tmp)
			return (ucptr1);
	}
	return (NULL);
}
