/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 10:05:52 by schakor           #+#    #+#             */
/*   Updated: 2017/12/06 10:48:36 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(dst) + ft_strlen(src);
	i = 0;
	while (dst[i] && i < n)
		++i;
	if (i == n)
		return (i + ft_strlen(src));
	j = 0;
	while (src[j] && i + j < n - 1)
	{
		dst[i + j] = src[j];
		++j;
	}
	dst[i + j] = '\0';
	return (len);
}
