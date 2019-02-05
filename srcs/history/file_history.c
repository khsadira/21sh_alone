/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:38:33 by khsadira          #+#    #+#             */
/*   Updated: 2018/11/28 14:24:43 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "twenty_one_sh.h"

static char		**file_to_buffer(int fd, char **buffer)
{
	int		ret;
	char	buff[2];
	char	*str;

	ret = 0;
	buff[0] = 0;
	buff[1] = 0;
	str = NULL;
	while ((ret = read(fd, buff, 1)) > 0)
	{
		buff[ret] = '\0';
		str = ft_strfreejoin(&str, buff);
	}
	if (str == NULL)
		return (NULL);
	close(fd);
	if (str)
		buffer = ft_strsplit(str, '\n');
	ft_strdel(&str);
	return (buffer);
}

void			history_from_file(t_shell *sh, char *path)
{
	char		**buff;
	int			i;
	int			fd;
	t_history	*new_ele;

	path = ft_strfreejoin(&path, "/.21sh_history");
	buff = NULL;
	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return ;
	buff = file_to_buffer(fd, buff);
	close(fd);
	while (buff && buff[i])
	{
		new_ele = new_hist(buff[i], ft_strlen(buff[i]), ft_strlen(buff[i]));
		sh->history = add_hist(sh->history, new_ele);
		i++;
	}
	i = 0;
	while (buff && buff[i])
		ft_strdel(&buff[i++]);
	if (buff)
		free(buff);
	ft_strdel(&path);
}

void			file_from_history(t_shell *sh, char *path)
{
	int		fd;
	char	*str;

	path = ft_strfreejoin(&path, "/.21sh_history");
	str = NULL;
	fd = open(path, O_WRONLY);
	if (fd < 0)
		fd = open(path, O_CREAT | O_WRONLY);
	if (fd > 0)
	{
		while (sh->history && sh->history->bfr)
			sh->history = sh->history->bfr;
		while (sh->history && sh->history->next)
		{
			str = ft_strfreejoin(&str, sh->history->buffer);
			str = ft_strfreejoin(&str, "\n");
			sh->history = sh->history->next;
		}
		if (str)
			write(fd, str, ft_strlen(str));
		ft_strdel(&str);
		ft_strdel(&path);
		close(fd);
	}
}
