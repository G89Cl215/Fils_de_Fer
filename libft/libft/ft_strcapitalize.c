/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:29:30 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:38:55 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *s)
{
	int		in_word;
	char	*str;

	in_word = 0;
	str = s;
	while (*str)
	{
		if (ft_isalnum(*str) && !in_word)
		{
			if (ft_islower(*str))
				*str -= 32;
			in_word = 1;
		}
		else if (ft_isupper(*str) && in_word)
			*str += 32;
		else if (!ft_isalnum(*str))
			in_word = 0;
		str++;
	}
	return (s);
}
