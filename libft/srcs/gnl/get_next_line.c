/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schakor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 16:42:26 by schakor           #+#    #+#             */
/*   Updated: 2018/09/28 15:13:24 by schakor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_fill(char **line, char **s1, char *s2)
{
	char	*tmp;

	*line = ft_strsub(*s1, 0, s2 - *s1);
	tmp = ft_strsub(*s1, s2 - *s1 + 1, ft_strlen(s2));
	free(*s1);
	*s1 = tmp;
	return (1);
}

static int		ft_reduce(char **over, char **line)
{
	if (!(*line = ft_strdup(*over)))
		return (-1);
	ft_strdel(over);
	return (1);
}

static void		ft_strfjoin(char **s1, char *s2)
{
	char	*tmp;

	tmp = ft_strjoin(*s1, s2);
	ft_strdel(s1);
	*s1 = tmp;
}

int				get_next_line(const int fd, char **line)
{
	static char	*over[NB_MAX_FD];
	char		buf[BUFF_SIZE + 1];
	char		*nl_ptr;
	int			rd;

	if (fd < 0 || BUFF_SIZE < 1 || !line || (rd = read(fd, buf, 0)) < 0)
		return (-1);
	if (!over[fd])
		if (!(over[fd] = ft_strnew(0)))
			return (-1);
	nl_ptr = ft_strchr(over[fd], '\n');
	while (nl_ptr == NULL && (rd = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rd] = '\0';
		ft_strfjoin(&over[fd], buf);
		nl_ptr = ft_strchr(over[fd], '\n');
	}
	if (nl_ptr != NULL)
		return (ft_fill(line, &over[fd], nl_ptr));
	if (ft_strlen(over[fd]) > 0)
		return (ft_reduce(&over[fd], line));
	ft_strdel(&over[fd]);
	return (0);
}
