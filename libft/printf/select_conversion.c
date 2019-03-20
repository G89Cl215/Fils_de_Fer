/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:41:40 by flviret           #+#    #+#             */
/*   Updated: 2019/03/07 12:52:31 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			clean_quit(char **conv, int ret)
{
	ft_strdel(conv);
	return (ret);
}

static int			ft_conv_double(t_flags *fl, t_buf *buf, va_list ap)
{
	char	*conv;

	if (fl->lm)
		conv = ft_ldtoa(va_arg(ap, long double), (fl->prc == -1) ? 6 : fl->prc);
	else
		conv = ft_dtoa(va_arg(ap, double), (fl->prc == -1) ? 6 : fl->prc);
	if (conv == NULL)
		return (0);
	if (!(ft_format_flag(fl, &conv)))
		return (clean_quit(&conv, 0));
	if (!(buf->str = ft_memjoin_free(buf->str, buf->len, conv,
					ft_strlen(conv))))
		return (clean_quit(&conv, 0));
	buf->len += ft_strlen(conv);
	return (1);
}

static int			conversion_extend(t_flags *fl, t_buf *buf, va_list ap)
{
	if (fl->c == 'f')
	{
		if (!(ft_conv_double(fl, buf, ap)))
			return (0);
	}
	else if (fl->c == 'p')
	{
		if (!(ft_conv_ptr(fl, buf, ap)))
			return (0);
	}
	else
		return (0);
	return (1);
}

int					conversion(t_flags *fl, t_buf *buf, va_list ap)
{
	if ((fl->l == 1 && (fl->c == 's' || fl->c == 'c')))
		return (0);
	if (ft_strchr(INT_CONV, fl->c) || ft_strchr(UINT_CONV, fl->c))
	{
		if (!(ft_conv_numeric(fl, buf, ap)))
			return (0);
	}
	else if (ft_strchr(CHAR_CONV, fl->c))
	{
		if (!(ft_conv_str(fl, buf, ap)))
			return (0);
	}
	else
		return (conversion_extend(fl, buf, ap));
	return (1);
}
