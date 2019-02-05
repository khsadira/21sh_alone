/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:36:08 by schakor           #+#    #+#             */
/*   Updated: 2018/09/28 16:43:59 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	char	*trim;
	size_t	start;
	size_t	len;

	if (s == NULL)
		return (NULL);
	start = 0;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		++start;
	if (!s[start])
	{
		if (!(trim = ft_strnew(1)))
			return (0);
		return (trim);
	}
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		--len;
	len = len - start + 1;
	if (!(trim = ft_strsub(s, start, len)))
		return (NULL);
	return (trim);
}
