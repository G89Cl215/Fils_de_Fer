/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 14:52:47 by flviret           #+#    #+#             */
/*   Updated: 2019/04/04 16:28:08 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int			compute_padding_len(t_flags *fl, int len, int sign)
{
	int		ret;

	ret = 0;
	if (fl->dz && ft_strchr(BASE_CONV, fl->c))
		ret = (fl->c == 'o') ? 1 : 2;
	if (ft_strchr(INT_CONV, fl->c))
	{
		ret += (fl->pl | fl->sp) & !sign;
	}
	return (len - ret);
}

static int	ft_zero_value_numeric_conv(t_flags *fl, char **conv, int sign)
{
	int	len;

	if (fl->prc == 0)
	{
		if (!(ft_zero_value_numeric_conv_zero_prc(fl, conv)))
			return (0);
	}
	else if (fl->prc > 0)
	{
		fl->dz = 0;
		ft_format_prc(fl, conv, &len);
	}
	len = ft_strlen(*conv);
	if (!(fl->pl | fl->sp))
	{
		if (!(format_no_sign(fl, conv, len, sign)))
			return (0);
	}
	else
	{
		if (!(format_sign(fl, conv, len, sign)))
			return (0);
	}
	return (1);
}

static int	ft_regular_conv(t_flags *fl, char **conv, int sign)
{
	int		len;

	if (ft_strchr(SEPARABLES, fl->c) && fl->com)
		if (!(ft_format_comma(fl, conv)))
			return (0);
	if (!(ft_format_prc(fl, conv, &len)))
		return (0);
	if ((ft_strchr(INT_CONV, fl->c) && (!(fl->pl | fl->sp)))
			|| (ft_strchr(BASE_CONV, fl->c) && fl->dz == 0))
	{
		if (!ft_format_padding(fl, conv, len, sign))
			return (0);
	}
	else if ((ft_strchr(BASE_CONV, fl->c) && fl->dz == 1))
	{
		if (!(dieze_position(fl, conv, len, sign)))
			return (0);
	}
	else
	{
		if (!(plus_position(fl, conv, len, sign)))
			return (0);
	}
	return (1);
}

int			ft_format_flag(t_flags *fl, char **conv)
{
	int	sign;

	sign = (*conv[0] == '-') ? 1 : 0;
	if (*conv[0] == '0' && fl->c != 'f')
	{
		if (!(ft_zero_value_numeric_conv(fl, conv, sign)))
			return (0);
	}
	else
	{
		if (!(ft_regular_conv(fl, conv, sign)))
			return (0);
	}
	return (1);
}
