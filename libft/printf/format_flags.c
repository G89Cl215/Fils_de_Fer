/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 14:15:52 by flviret           #+#    #+#             */
/*   Updated: 2019/04/04 16:28:04 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int			ft_format_plus_space(t_flags *fl, char **conv, int sign)
{
	char	*tmp;

	if (fl->pl)
		fl->sp = 0;
	if (ft_strchr(INT_CONV, fl->c) || fl->c == 'f')
	{
		if (sign == 0)
		{
			tmp = *conv;
			if (!(*conv = ft_strjoin((fl->pl) ? "+" : " ", *conv)))
				return (0);
			ft_strdel(&tmp);
		}
		fl->sp = 0;
	}
	fl->pl = 0;
	return (1);
}

int			dieze_position(t_flags *fl, char **conv, int len, int sign)
{
	if ((fl->f0 == 1 && fl->prc == -1))
	{
		if (!ft_format_padding(fl, conv, len, sign))
			return (0);
		fl->dz = 0;
		if (!ft_format_diese(fl, conv))
			return (0);
	}
	else
	{
		if (!ft_format_diese(fl, conv))
			return (0);
		fl->dz = 0;
		if (!ft_format_padding(fl, conv, len, sign))
			return (0);
	}
	return (1);
}

int			plus_position(t_flags *fl, char **conv, int len, int sign)
{
	if ((fl->f0 == 1 && fl->prc == -1))
	{
		if (!ft_format_padding(fl, conv, len, sign))
			return (0);
		if (fl->sp | fl->pl)
		{
			if (!(ft_format_plus_space(fl, conv, sign)))
				return (0);
		}
	}
	else
	{
		if (fl->sp | fl->pl)
		{
			if (!(ft_format_plus_space(fl, conv, sign)))
				return (0);
		}
		if (!ft_format_padding(fl, conv, len, sign))
			return (0);
	}
	return (1);
}

int			format_no_sign(t_flags *fl, char **conv, int len, int sign)
{
	if (fl->pad > len)
	{
		fl->dz = 0;
		if (!ft_format_padding(fl, conv, len, sign))
			return (0);
	}
	return (1);
}

int			format_sign(t_flags *fl, char **conv, int len, int sign)
{
	if (fl->f0 && fl->prc == -1)
	{
		if (fl->pad > len)
		{
			fl->dz = 0;
			if (!ft_format_padding(fl, conv, len, sign))
				return (0);
		}
		if (!(ft_format_plus_space(fl, conv, sign)))
			return (0);
	}
	else
	{
		if (!(ft_format_plus_space(fl, conv, sign)))
			return (0);
		if (fl->pad > len)
		{
			fl->dz = 0;
			if (!ft_format_padding(fl, conv, len, sign))
				return (0);
		}
	}
	return (1);
}
