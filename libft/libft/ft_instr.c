/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 11:23:29 by flviret           #+#    #+#             */
/*   Updated: 2019/03/05 11:38:08 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_instr(const char c, const char *accept)
{
	while (*accept)
	{
		if (c == *accept)
			return (1);
		accept++;
	}
	return (0);
}
