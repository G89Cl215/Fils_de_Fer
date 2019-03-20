/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flviret <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 11:56:21 by flviret           #+#    #+#             */
/*   Updated: 2019/03/19 14:24:11 by flviret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		retnextline(char **str, const int fd, char **line)
{
	size_t len;

	len = 0;
	while (str[fd][len] && str[fd][len] != '\n')
		len++;
	if (len != 0 || ft_strlen(str[fd]) > 0)
	{
		*line = ft_strsub(str[fd], 0, len);
		len += (len == ft_strlen(str[fd])) ? 0 : 1;
		str[fd] = ft_strsubfree(str[fd], len, ft_strlen(str[fd]));
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int				reid;
	char			readance[BUFF_SIZE + 1];
	static char		*str[10240];

	if (line == NULL || fd < 0 || fd > 10240 || BUFF_SIZE < 1)
		return (-1);
	if (str[fd] == NULL)
		if ((str[fd] = ft_strnew(0)) == NULL)
			return (-1);
	while (!(ft_strchr(str[fd], '\n')) &&
			(reid = read(fd, readance, BUFF_SIZE)) > 0)
	{
		readance[reid] = '\0';
		if (!(str[fd] = ft_strjoinfree(str[fd], readance)))
			return (0);
	}
	if (reid == -1)
		return (-1);
	return (retnextline(str, fd, line));
}
