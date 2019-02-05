/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 20:51:15 by schakor           #+#    #+#             */
/*   Updated: 2017/11/30 08:35:21 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	i;

	ret = NULL;
	if (s != NULL && f != NULL)
	{
		if (!(ret = (char *)malloc(sizeof(*ret) * (ft_strlen(s) + 1))))
			return (NULL);
		i = 0;
		while (s[i])
		{
			ret[i] = (*f)(i, (char)s[i]);
			++i;
		}
		ret[i] = '\0';
	}
	return (ret);
}
