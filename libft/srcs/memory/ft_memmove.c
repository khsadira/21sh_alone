/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:40:20 by schakor           #+#    #+#             */
/*   Updated: 2017/12/06 10:47:09 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*cptr1;
	unsigned char	*cptr2;

	cptr1 = (unsigned char *)dst;
	cptr2 = (unsigned char *)src;
	if (cptr1 < cptr2)
		return (ft_memcpy(dst, src, n));
	cptr1 += n - 1;
	cptr2 += n - 1;
	while (n--)
		*cptr1-- = *cptr2--;
	return (dst);
}
