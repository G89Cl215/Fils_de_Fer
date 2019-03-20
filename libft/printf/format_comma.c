/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_comma.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:08:36 by flviret           #+#    #+#             */
/*   Updated: 2019/02/21 15:11:45 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*clean_quit(char **dup, char **tmp, char *ret)
{
	ft_strdel(dup);
	ft_strdel(tmp);
	return (ret);
}

static char	*format_copy(const char *tmp)
{
	int		i;
	int		j;
	int		len;
	int		com;
	char	*new;

	len = ft_strlen(tmp);
	j = len - 1;
	len += (len / 3 - ((len % 3 == 0) ? 1 : 0));
	i = 0;
	com = 0;
	if (!(new = ft_memalloc(len + 1)))
		return (NULL);
	while ((i + com) < len)
	{
		if (i % 3 == 0 && i != 0 && new[i + com - 1] != ',')
			new[i + com++] = ',';
		else
			new[i++ + com] = tmp[j--];
	}
	ft_strrev(new);
	return (new);
}

static char	*comma_double(char *new, const char *conv, char *dup)
{
	char	*tmp;

	tmp = new;
	if (!(new = ft_strjoin(new, ft_strchr(conv, '.'))))
		return (clean_quit(&dup, &tmp, NULL));
	return (clean_quit(&dup, &tmp, new));
}

static char	*format_comma_separator(t_flags *fl, const char *conv)
{
	int		len;
	char	*new;
	char	*tmp;
	char	*dup;

	tmp = (char*)conv;
	dup = NULL;
	if (fl->c == 'f')
	{
		if (!(tmp = ft_strchr(conv, '.')))
			return (NULL);
		len = tmp - conv;
		if (!(dup = ft_strsub(conv, 0, len)))
			return (NULL);
		tmp = dup;
	}
	if (!(new = format_copy(tmp)))
		return (clean_quit(&dup, NULL, NULL));
	if (fl->c == 'f')
		return (comma_double(new, conv, dup));
	return (new);
}

int			ft_format_comma(t_flags *fl, char **conv)
{
	char	*tmp;

	tmp = *conv;
	if (!(*conv = format_comma_separator(fl, *conv)))
		*conv = tmp;
	else
		ft_strdel(&tmp);
	return (1);
}
