#include "twenty_one_sh.h"

typedef struct	s_var
{
	size_t	bufsize;
	size_t	tmpsize;
	size_t	exclaim_type;
}		t_var;

static t_var	var;

static char	*ft_memfreejoin(char **s1, char *s2, size_t bufsize, size_t tmpsize)
{
	char	*tmp;

	tmp = NULL;
	if (!(mp = (char *)malloc(sizeof(char) * (bufsize + tmpsize))))
		return (NULL);
	ft_memcpy(tmp, *s1, bufsize);
	ft_memcpy(mp + bufsize, s2, tmpsize);
	if (bufsize > 0)
		free(*s1);
	return (tmp);
}

static size_t	end_and_fine_type(size_t i, size_t j, char **tmp, t_shell *sh)
{
	j = i + 1
	if (!(j < sh->in->bufsize))
		return (-1);
	if (sh->in->buffer[j] == '!')
	{
		j++;
		var.exclaim_type = 1;
	}
	else if (ft_isalpha(sh->in->buffer[j]))
	{
		while (j < sh->in->bufsize && ft_isalnum(sh->in->buffer[j]))
			j++;
		var.exclaim_type = 2;
	}
	else if (ft_isdigit(sh->in->buffer[j]))
	{
		while (j < sh->in->bufsize && ft_isdigit(sh->in->buffer[j]))
			j++;
		var.exclaim_type = 3;
	}
	return (j);
}

static char	*replace_exclaim_one(t_shell *sh)
{
	char	*tmp;

	tmp = ft_memalloc(sh->history->bufsize);
	tmp = ft_memcpy(tmp, sh->history->buffer, sh->history->bufsize);
	var.tmpsize = sh->history->bufsize;
	return (tmp);
}

static size_t	my_memcmp(char	*s1, t_history *hist, size_t i, size_t j)
{
	size_t taille;
	size_t k;

	k = 0;
	taille = j - i;
	while (k < hist->bufsize && i < j)
	{
		if (s1[i] != hist->buffer[k])
			return (0);
		k++;
		i++;
	}
	if (!(k < hist->bufsize))
		return (1);
	return (0);
}

static char	*replace_exclaim_two(t_shell *sh, size_t i, size_t j)
{
	t_history	*tmp_hist;
	char		*tmp;

	tmp_hist = sh->history;
	i++;
	while (tmp_hist)
	{
		if (sh->in->buffer[i] == tmp_hist->buffer[0])
		{
			if (my_memcmp(sh->in->buffer, tmp_hist, i, j))
			{
				tmp = ft_memalloc(tmp_hist->bufsize);
				tmp = ft_memcpy(tmp, tmp_hist->buffer, tmp_hist->bufsize);
				var.tmpsize = tmp_hist->bufsize;
				return (tmp);
			}
		}
		tmp_hist = tmp_hist->bfr;
	}
	return (tmp);
}

static char	*replace_exclaim_three(t_shell *sh, size_t i, size_t j)
{
	char	*tmp;
	size_t	nb;
	size_t	stock;
	size_t	start;
	t_history	*tmp_hist;

	nb = 0;
	while (stock--)
	{
		nb *= 10;
		nb += (int)(sh->in->buffer[i]) - 48;
		i++;
	}
	tmp_hist = sh->history;
	while (tmp_hist->bfr)
		tmp_hist = tmp_hist->bfr;
	while (--nb)
		tmp_hist = tmp_hist->next;
	// if (!history)
	// return (NULL);
	tmp = ft_memalloc(tmp_hist->bufsize);
	tmp = ft_memcpy(tmp, tmp_hist->buffer, tmp_hist->bufsize);
	var.tmpsize = tmp_hist->bufsize;
	return (tmp);
}

void	exclaim(t_shell *sh)
{
}
