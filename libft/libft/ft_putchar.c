/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:27:28 by flviret           #+#    #+#             */
/*   Updated: 2019/04/04 15:35:53 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	char	l;

	if (!(c & 0x80))
		write(1, &c, 1);
	else
	{
		l = ((unsigned char)c <= 191 ? 0xC2 : 0xC3);
		l = (char)(0xC2 | ((unsigned char)l));
		write(1, &l, 1);
		l = (char)(0xBF & c);
		write(1, &l, 1);
	}
}
