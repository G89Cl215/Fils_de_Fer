/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 16:50:46 by tgouedar          #+#    #+#             */
/*   Updated: 2019/03/23 16:21:02 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "option.h"
#include "libft.h"

static int		ft_usage(char arg)
{
	ft_putstr("FdF: illegal option -- ");
	ft_putchar(arg);
	ft_putchar('\n');
	ft_putstr("usage: ./ft_ls [-");
	ft_putstr(OPT);
	ft_putendl("] [file ...]");
	return (0);
}

static void		ft_taiga(char opt, t_options *options)
{
	if (opt == 'w')
		options->w = 1;
}

static int		ft_fill_option(char *arg, t_options *options)
{
	arg++;
	while (*arg && ft_isin(*arg, OPT))
	{
		ft_taiga(*arg, options);
		arg++;
	}
	if (*arg && !ft_isin(*arg, OPT))
		return (ft_usage(*arg));
	return (1);
}

int				ft_option(int ac, char **av, t_options *options)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-' && !(ft_fill_option(av[i], options)))
			return (0);
	}
	return (1);
}
