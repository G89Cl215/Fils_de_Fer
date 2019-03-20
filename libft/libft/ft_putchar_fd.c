/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:27:42 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:38:44 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	char	l;

	if (!(c & 0x80))
		write(fd, &c, 1);
	else
	{
		l = ((unsigned char)c <= 191 ? 0xC2 : 0xC3);
		l = (char)(0xc2 | ((unsigned char)l));
		write(fd, &l, 1);
		l = (char)(0xBF & c);
		write(fd, &l, 1);
	}
}
