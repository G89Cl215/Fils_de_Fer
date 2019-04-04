/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 13:07:28 by flviret           #+#    #+#             */
/*   Updated: 2019/04/04 16:26:35 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static int	clean_quit(char **conv, int ret)
{
	ft_strdel(conv);
	return (ret);
}

static char	*ft_conv_string(va_list ap)
{
	char	*arg;
	char	*conv;

	arg = va_arg(ap, char*);
	if (arg == NULL)
	{
		if (!(conv = ft_strdup("(null)")))
			return (NULL);
	}
	else
	{
		if (!(conv = ft_strdup(arg)))
			return (NULL);
	}
	return (conv);
}

int			ft_conv_str(t_flags *fl, t_buf *buf, va_list ap)
{
	char	*conv;

	conv = NULL;
	if (fl->c == 'c')
		return (ft_format_char(fl, buf, (unsigned char)va_arg(ap, int)));
	else if (fl->c == '%')
		return (ft_format_char(fl, buf, (unsigned char)'%'));
	else if (fl->c == 's')
	{
		if (!(conv = ft_conv_string(ap)))
			return (0);
	}
	if (!(ft_format_str(fl, &conv, ft_strlen(conv), buf)))
		return (clean_quit(&conv, 0));
	return (1);
}
