/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_regular_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 15:41:08 by flviret           #+#    #+#             */
/*   Updated: 2019/04/04 16:29:18 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static int	clean_quit(char **substr, char **conv, char **tmp, int ret)
{
	ft_strdel(substr);
	ft_strdel(conv);
	ft_strdel(tmp);
	return (ret);
}

static int	ft_signed_exception_padding(char **conv, char **substr)
{
	char	*tmp;

	tmp = *substr;
	if (!(*substr = ft_strjoin("-", *substr)))
		return (clean_quit(NULL, NULL, &tmp, 0));
	ft_strdel(&tmp);
	tmp = *conv;
	if (!(*conv = ft_strjoin(*substr, (*conv) + 1)))
		return (clean_quit(substr, NULL, &tmp, 0));
	ft_strdel(&tmp);
	ft_strdel(substr);
	return (1);
}

static int	ft_exception_padding(t_flags *fl, char **conv, int len, int sign)
{
	char	*substr;
	char	*tmp;
	int		ret;

	if (!(substr = (char*)ft_memalloc(len + 1)))
		return (0);
	if ((ret = compute_padding_len(fl, len, sign)) > 0)
		substr = ft_memset((void*)substr, '0', ret);
	if (sign)
	{
		if (!(ft_signed_exception_padding(conv, &substr)))
			return (clean_quit(&substr, conv, NULL, 0));
	}
	else
	{
		tmp = *conv;
		if (!(*conv = ft_strjoin_free(substr, *conv)))
			return (clean_quit(&substr, NULL, &tmp, 0));
	}
	if (fl->dz)
	{
		if (!(ft_format_diese(fl, conv)))
			return (0);
	}
	return (1);
}

static int	ft_format_padding_minus(t_flags *fl, char **conv, int len)
{
	char	*substr;

	if (len > 0)
	{
		if (!(substr = (char*)ft_memalloc(len + 1)))
			return (0);
		if (fl->dz)
		{
			if (!(ft_format_diese(fl, conv)))
				return (clean_quit(&substr, NULL, NULL, 0));
			fl->dz = 0;
		}
		if (fl->pl | fl->sp)
		{
			if (!(ft_format_plus_space(fl, conv, (*conv[0] == '-') ? 1 : 0)))
				return (clean_quit(&substr, NULL, NULL, 0));
		}
		len = fl->pad - ft_strlen(*conv);
		substr = (len > 0) ? ft_memset((void*)substr, ' ', len) : 0;
		if (!(*conv = ft_strjoin_free((fl->mo) ? *conv : substr,
					(fl->mo) ? substr : *conv)))
			return (clean_quit(&substr, NULL, NULL, 0));
	}
	return (1);
}

int			ft_format_padding(t_flags *fl, char **conv, int len, int sign)
{
	len = fl->pad - len;
	if (len <= 0)
	{
		if (fl->dz)
		{
			if (!(ft_format_diese(fl, conv)))
				return (0);
		}
		return (1);
	}
	if (fl->f0 && fl->mo == 0 && (fl->prc == -1 || fl->c == 's'))
	{
		if (!(ft_exception_padding(fl, conv, len, sign)))
			return (0);
	}
	else
	{
		if (!(ft_format_padding_minus(fl, conv, len)))
			return (0);
	}
	return (1);
}
