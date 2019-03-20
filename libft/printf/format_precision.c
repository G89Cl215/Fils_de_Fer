/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:14:04 by flviret           #+#    #+#             */
/*   Updated: 2019/03/07 15:35:22 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_format_diese(t_flags *fl, char **conv)
{
	char	*tmp;

	tmp = *conv;
	if ((fl->dz && (fl->c == 'x' | fl->c == 'X'
					| (fl->c == 'o' & *conv[0] != '0')
					| (fl->c == 'f' & fl->prc == 0))) || (fl->c == 'p'))
	{
		if (fl->c == 'x' || fl->c == 'X' || fl->c == 'p')
			if (!(*conv = ft_strjoin("0X", *conv)))
				return (0);
		if (fl->c == 'o')
			if (!(*conv = ft_strjoin("0", *conv)))
				return (0);
		if (fl->c == 'f')
			if (!(*conv = ft_strjoin(*conv, ".")))
				return (0);
		fl->dz = 0;
		ft_strdel(&tmp);
	}
	return (1);
}

static int	ft_string_prc(t_flags *fl, char **conv)
{
	char	*tmp;

	tmp = *conv;
	if (!(*conv = ft_strndup(*conv, fl->prc)))
		return (0);
	ft_strdel(&tmp);
	return (1);
}

static int	ft_numeric_prc(t_flags *fl, char **conv, int len)
{
	char	*substr;

	len = fl->prc - len;
	if (*conv[0] == '-')
	{
		*conv[0] = '0';
		if (!(substr = (char*)ft_memalloc(len + 1)))
			return (0);
		substr = ft_memset((void*)substr, '0', len);
		substr[0] = '-';
	}
	else
	{
		if (!(substr = (char*)ft_memalloc(len + 1)))
			return (0);
		substr = ft_memset((void*)substr, '0', len);
	}
	if (!(*conv = ft_strjoin_free(substr, *conv)))
	{
		ft_strdel(&substr);
		return (0);
	}
	return (1);
}

int			ft_zero_value_numeric_conv_zero_prc(t_flags *fl, char **conv)
{
	ft_strdel(conv);
	if (fl->dz && (fl->c == 'o' || fl->c == 'p'))
	{
		if (fl->c == 'o')
			if (!(*conv = ft_strdup("0")))
				return (0);
		if (fl->c == 'p')
			if (!(*conv = ft_strdup("0x")))
				return (0);
	}
	else if (!(*conv = ft_strdup("\0")))
		return (0);
	fl->dz = 0;
	return (1);
}

int			ft_format_prc(t_flags *fl, char **conv, int *len)
{
	*len = ft_strlen(*conv);
	if (fl->prc < *len && fl->c == 's')
	{
		if (!(ft_string_prc(fl, conv)))
			return (0);
	}
	else if (fl->prc >= *len && (ft_strchr(INT_CONV, fl->c)
				|| ft_strchr(UINT_CONV, fl->c) || fl->c == 'p'))
	{
		if (*conv[0] == '-')
			(*len)--;
		if (!(ft_numeric_prc(fl, conv, *len)))
			return (0);
	}
	*len = ft_strlen(*conv);
	return (1);
}
