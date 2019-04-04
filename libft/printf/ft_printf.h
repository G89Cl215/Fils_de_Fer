/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 00:07:50 by flviret           #+#    #+#             */
/*   Updated: 2019/04/04 16:32:30 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>

# define ALL_FLAGS	"*Llh+- .#0123456789,"
# define ALL_CONV	"cspdiouxXf%"
# define INT_CONV	"di"
# define UINT_CONV	"ouxX"
# define BASE_CONV	"oxX"
# define CHAR_CONV	"cs%"
# define SEPARABLES	"iduf"

typedef struct	s_buf
{
	void			*str;
	size_t			len;
}				t_buf;

typedef struct	s_flags
{
	unsigned short	hh	: 1;
	unsigned short	h	: 1;
	unsigned short	l	: 1;
	unsigned short	ll	: 1;
	unsigned short	lm	: 1;
	unsigned short	dz	: 1;
	unsigned short	f0	: 1;
	unsigned short	mo	: 1;
	unsigned short	pl	: 1;
	unsigned short	sp	: 1;
	unsigned short	com	: 1;
	unsigned short	star: 1;
	unsigned short	base: 5;
	int				prc;
	int				pad;
	char			c;
}				t_flags;

int				ft_printf(const char *format, ...);
int				ft_sprintf(char *str, const char *format, ...);
int				ft_snprintf(char *s, size_t size, const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_vprintf(const char *format, va_list ap);
int				ft_vsprintf(char *s, const char *format, va_list ap);
int				ft_vsnprintf(char *s, size_t size, const char *format,
					va_list ap);
int				ft_vdprintf(int fd, const char *format, va_list ap);
t_buf			*init_buf(void);
t_flags			*init_flags(void);
void			add_flag(const char c, t_flags *fl);
int				parse_format(const char **format, t_buf *buf);
int				parse_flags(const char **format, t_buf *buf, va_list ap);
int				conversion(t_flags *fl, t_buf *buf, va_list ap);
int				ft_conv_numeric(t_flags *fl, t_buf *buf, va_list ap);
int				ft_conv_str(t_flags *fl, t_buf *buf, va_list ap);
int				ft_conv_ptr(t_flags *fl, t_buf *buf, va_list ap);
int				ft_format_flag(t_flags *fl, char **conv);
int				ft_format_prc(t_flags *fl, char **conv, int *len);
int				ft_zero_value_numeric_conv_zero_prc(t_flags *fl, char **conv);
int				ft_format_plus_space(t_flags *fl, char **conv, int sign);
int				compute_padding_len(t_flags *fl, int len, int sign);
int				ft_format_padding(t_flags *fl, char **conv, int len, int sign);
int				ft_format_diese(t_flags *fl, char **conv);
int				ft_format_char(t_flags *fl, t_buf *buf, unsigned char c);
int				ft_format_str(t_flags *fl, char **conv, int len, t_buf *buf);
int				dieze_position(t_flags *fl, char **conv, int len, int sign);
int				plus_position(t_flags *fl, char **conv, int len, int sign);
int				format_sign(t_flags *fl, char **conv, int len, int sign);
int				format_no_sign(t_flags *fl, char **conv, int len, int sign);
int				ft_format_comma(t_flags *fl, char **conv);

#endif
