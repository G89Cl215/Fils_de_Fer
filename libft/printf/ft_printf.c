/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 17:40:58 by flviret           #+#    #+#             */
/*   Updated: 2019/04/04 16:29:39 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"
#include <unistd.h>

static int	clean_quit(t_buf *buf, va_list ap, int ret)
{
	size_t	len;

	len = 0;
	va_end(ap);
	if (buf != NULL)
	{
		len = buf->len;
		ft_memdel(&buf->str);
		ft_memdel((void*)&buf);
	}
	if (ret == 0)
		return (-1);
	return (len);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_buf	*buf;

	if (!(buf = init_buf()))
		return (clean_quit(buf, ap, 0));
	va_start(ap, format);
	while (*format)
	{
		if (*format && *format != '%')
		{
			if (parse_format(&format, buf) <= 0)
			{
				write(1, buf->str, buf->len);
				return (clean_quit(buf, ap, 1));
			}
		}
		if (*format && *format == '%')
			if (!(parse_flags(&format, buf, ap)))
				return (clean_quit(buf, ap, 0));
	}
	write(1, buf->str, buf->len);
	return (clean_quit(buf, ap, 1));
}
