/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 00:08:02 by flviret           #+#    #+#             */
/*   Updated: 2019/04/04 16:30:46 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

static int	clean_quit(t_flags **fl, int ret)
{
	ft_memdel((void**)fl);
	return (ret);
}

static void	add_numeric_flags(t_flags *fl, const char **format, va_list ap)
{
	if (**format == '.')
	{
		(*format)++;
		fl->prc = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	if (ft_isdigit(**format) && **format != '0')
	{
		fl->pad = ft_atoi(*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	if (**format == '*' && (*format)++)
		fl->pad = va_arg(ap, int);
}

static int	ft_parse_extend(const char **format, t_buf *buf, va_list ap,
		t_flags *fl)
{
	if (ft_instr(**format, ALL_CONV))
	{
		fl->c = **format;
		if (fl->c == 'o')
			fl->base = 8;
		else if (fl->c == 'x' || fl->c == 'X')
			fl->base = 16;
		if (!(conversion(fl, buf, ap)))
			return (clean_quit(&fl, 0));
		if (**format)
			(*format)++;
	}
	return (1);
}

int			parse_flags(const char **format, t_buf *buf, va_list ap)
{
	t_flags	*fl;

	if (!(fl = init_flags()))
		return (0);
	(*format)++;
	while (**format && ft_instr(**format, ALL_FLAGS))
	{
		add_flag(**format, fl);
		if (**format == '.' || **format == '*' || (ft_isdigit(**format)
					&& **format != '0'))
			add_numeric_flags(fl, format, ap);
		else
			(*format)++;
	}
	ft_parse_extend(format, buf, ap, fl);
	return (clean_quit(&fl, 1));
}
