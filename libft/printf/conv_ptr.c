/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_ptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:07:23 by flviret           #+#    #+#             */
/*   Updated: 2019/04/03 13:53:08 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	clean_quit(char **conv, int ret)
{
	ft_strdel(conv);
	return (ret);
}

static char	*ft_conv_null_ptr(t_flags *fl)
{
	void	*tmp;
	char	*conv;

	if (fl->prc <= 0)
	{
		if (!(conv = ft_strdup((fl->prc == -1) ? "0x0" : "0x")))
			return (NULL);
	}
	else
	{
		if (!(conv = ft_memalloc(fl->prc + 1)))
			return (NULL);
		ft_bzero(conv, sizeof(char) * (fl->prc + 1));
		tmp = conv;
		if (!(conv = ft_strjoin("0x", conv)))
		{
			ft_strdel(&conv);
			return (NULL);
		}
		ft_memdel(&tmp);
	}
	return (conv);
}

static int	ft_format_null_ptr(t_flags *fl, char **conv, t_buf *buf)
{
	char	*tmp;

	if (!(*conv = ft_conv_null_ptr(fl)))
		return (0);
	if (!(ft_format_padding(fl, conv, ft_strlen(*conv), 0)))
		return (0);
	else if (fl->pad != -1 && fl->f0 && fl->prc == -1 && fl->mo == 0)
	{
		tmp = ft_strrchr(*conv, 'x');
		if (tmp)
		{
			*tmp = '0';
			*(*conv + 1) = 'x';
		}
	}
	if (!(buf->str = ft_memjoin_free(buf->str, buf->len, *conv,
			ft_strlen(*conv))))
		return (clean_quit(conv, 0));
	buf->len += ft_strlen(*conv);
	return (1);
}

static int	ft_format_ptr(t_flags *fl, char **conv)
{
	int		len;

	if (!(ft_format_prc(fl, conv, &len)))
		return (0);
	if (fl->f0 == 1 && fl->pad != -1)
	{
		if (!(ft_format_padding(fl, conv, len + 2, 0)))
			return (0);
		if (!(ft_format_diese(fl, conv)))
			return (0);
	}
	else
	{
		if (!(ft_format_diese(fl, conv)))
			return (0);
		if (!(ft_format_padding(fl, conv, len, 0)))
			return (0);
	}
	return (1);
}

int			ft_conv_ptr(t_flags *fl, t_buf *buf, va_list ap)
{
	void	*ptr;
	char	*conv;

	ptr = va_arg(ap, void*);
	if (ptr == 0)
	{
		if (!(ft_format_null_ptr(fl, &conv, buf)))
			return (0);
		return (1);
	}
	else
	{
		if (!(conv = ft_ultoa_base((unsigned long)&(*ptr), 16)))
			return (0);
	}
	if (!(ft_format_ptr(fl, &conv)))
		return (0);
	conv = ft_strlowcase(conv);
	if (!(buf->str = ft_memjoin_free(buf->str, buf->len, conv,
			ft_strlen(conv))))
		return (clean_quit(&conv, 0));
	buf->len += ft_strlen(conv);
	return (1);
}
