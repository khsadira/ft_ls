/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 10:43:46 by khsadira          #+#    #+#             */
/*   Updated: 2018/09/02 15:58:32 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_ls_print(int ac, int nb_flag, t_lst *list)
{
	if (ac - nb_flag > 2 && list->bfr)
	{
		ft_putstr(list->name);
		ft_putendl(":");
	}
	else if (!list->bfr && ac - nb_flag > 2)
	{
		ft_putchar(10);
		ft_putstr(list->name);
		ft_putendl(":");
	}
}

static void	ft_ls_end(t_flag *flag, t_lst *rep, DIR *dir)
{
	long long int	nb;
	t_lst			*lst_dir;
	t_size			*size_l;

	nb = 0;
	size_l = NULL;
	lst_dir = ft_make_list(dir, flag, rep->name);
	if (flag && flag->l == 1)
	{
		size_l = ft_format(lst_dir);
		nb = ft_blocks(lst_dir);
	}
	ft_lstprint(lst_dir, flag, size_l, nb);
	if (flag->rec == 1)
		ft_ls_r(flag, lst_dir);
	if (flag && flag->l == 1)
		free(size_l);
	if (lst_dir != NULL)
		ft_lst_free(&lst_dir);
}

void		ft_ls(t_flag *flag, t_lst *rep, int ac, int nb_flag)
{
	DIR				*dir;

	while (rep && rep->name)
	{
		if (!(dir = opendir(rep->name)))
		{
			ft_error(rep->name);
			rep = rep->next;
		}
		else
		{
			ft_ls_print(ac, nb_flag, rep);
			ft_ls_end(flag, rep, dir);
			if (closedir(dir) == -1)
				ft_error(rep->name);
			rep = rep->next;
		}
	}
}
