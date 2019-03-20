/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 19:42:23 by flviret           #+#    #+#             */
/*   Updated: 2019/03/06 11:35:59 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		clean_quit(char **scat, char **tmp, int ret)
{
	ft_strdel(scat);
	ft_strdel(tmp);
	return (ret);
}

static int		create_str(const char **format, t_buf *buf, int nxt_kwd)
{
	if (nxt_kwd > 0)
	{
		if (!(buf->str = ft_strndup(*format, nxt_kwd)))
			return (0);
	}
	else
	{
		if (!(buf->str = ft_strdup(*format)))
			return (0);
		buf->len += ft_strlen(buf->str);
		return (-1);
	}
	*format += nxt_kwd;
	buf->len += ft_strlen(buf->str);
	return (1);
}

static int		append_str(const char **format, t_buf *buf, int nxt_kwd)
{
	char	*tmp;
	char	*scat;

	tmp = (char*)buf->str;
	if (nxt_kwd > 0)
	{
		if (!(scat = ft_strndup(*format, nxt_kwd)))
			return (0);
		if (!(buf->str = ft_memjoin(buf->str, buf->len, scat, ft_strlen(scat))))
			return (clean_quit(&scat, NULL, 0));
		buf->len += ft_strlen(scat);
		ft_strdel(&scat);
	}
	else
	{
		if (!(scat = ft_strdup(*format)))
			return (0);
		if (!(buf->str = ft_memjoin(buf->str, buf->len, scat, ft_strlen(scat))))
			return (clean_quit(&scat, &tmp, 0));
		buf->len += ft_strlen(scat);
		return (clean_quit(&scat, &tmp, 0));
	}
	*format += nxt_kwd;
	return (clean_quit(NULL, &tmp, 1));
}

int				parse_format(const char **format, t_buf *buf)
{
	int		nxt_kwd;
	char	*nxt;

	nxt = ft_strpbrk(*format, "%{");
	if (nxt == NULL)
		nxt_kwd = 0;
	else
		nxt_kwd = nxt - *format;
	if (buf->str == NULL)
		return (create_str(format, buf, nxt_kwd));
	return (append_str(format, buf, nxt_kwd));
}
