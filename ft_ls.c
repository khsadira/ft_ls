/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 10:43:46 by khsadira          #+#    #+#             */
/*   Updated: 2018/06/26 16:33:41 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(t_flag *flag, t_lst *rep, int ac, int nb_flag)
{
	long long int	nb;
	int				i;
	DIR				*dir;
	t_lst			*lst_dir;
	t_size			*size_l;
	i = 0;

	lst_dir = NULL;
	size_l = NULL;
	while (rep && rep->name)
	{
		if (!(dir = opendir(rep->name)))
		{
			ft_error(errno, rep->name);
			rep = rep->next;
			i++;
		}
		else
		{
			if (ac - nb_flag > 2 && i == 0)
			{
				ft_putstr(rep->name);
				ft_putendl(":");
			}
			else if (i != 0 && ac - nb_flag > 2)
			{
				ft_putchar(10);
				ft_putstr(rep->name);
				ft_putendl(":");
			}
			lst_dir = ft_make_list(dir, flag, rep->name);
			if (flag && flag->l == 1)
			{
				size_l = ft_format(lst_dir);	
				nb = ft_blocks(lst_dir);
			}
			ft_lstprint(lst_dir, flag, size_l, nb);
			if (flag->R == 1)
				ft_ls_r(flag, lst_dir);
			if (flag && flag->l == 1)
				free(size_l);
			if (lst_dir != NULL)
				ft_lst_free(&lst_dir);
			if (closedir(dir) == -1)
				ft_error(errno, rep->name);
			rep = rep->next;
			i++;
		}
	}
}
