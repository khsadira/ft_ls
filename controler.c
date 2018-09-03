/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 10:45:37 by khsadira          #+#    #+#             */
/*   Updated: 2018/09/03 10:02:41 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int		ft_nb_flag(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (av[i][0] != '-')
			return (i - 1);
		i++;
	}
	return (i - 1);
}

int				main(int ac, char **av)
{
	t_flag		*flag;
	t_lst		*rep;
	int			nb_flag;

	nb_flag = ft_nb_flag(av);
	flag = convert_to_flag(av);
	rep = convert_to_dir(ac, av, flag);
	ft_ls(flag, rep, ac, nb_flag);
	ft_lst_free(&rep);
	free(flag);
	return (0);
}
