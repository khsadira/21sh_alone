/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 13:00:19 by schakor           #+#    #+#             */
/*   Updated: 2018/10/05 18:46:15 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinjoin(char *s1, char *s2, char *s3)
{
	char	*ret;
	size_t	len1;
	size_t	len2;
	size_t	len3;

	if (s1 == NULL || s2 == NULL || s3 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len3 = ft_strlen(s3);
	if (!(ret = (char *)malloc(sizeof(*ret) * (len1 + len2 + len3 + 1))))
		return (NULL);
	ft_strcpy(ret, s1);
	ft_strcpy(ret + len1, s2);
	ft_strcpy(ret + len1 + len2, s3);
	return (ret);
}
