/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:23:43 by khsadira          #+#    #+#             */
/*   Updated: 2018/08/31 11:56:01 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_free_lst(t_lst **list)
{
	free((*list)->name);
	free(*list);
}

static void		ft_ls_r_r(t_flag *flag, t_lst *list)
{
	t_lst	*l_list;

	while (list && list->next)
		list = list->next;
	while (list)
	{
		if (S_ISDIR(list->buf.st_mode) && ft_strcmp(list->name, ".") != 0 &&
				ft_strcmp(list->name, "..") != 0)
		{
			l_list = ft_newele(ft_strdup(list->path));
			ft_putstr("\n");
			ft_putstr(l_list->name);
			ft_putstr(":\n");
			ft_ls(flag, l_list, 1, 0);
			ft_free_lst(&l_list);
		}
		list = list->bfr;
	}
}

void			ft_ls_r(t_flag *flag, t_lst *list)
{
	t_lst	*l_list;

	if (flag && flag->r)
		ft_ls_r_r(flag, list);
	else
	{
		while (list)
		{
			if (S_ISDIR(list->buf.st_mode) && ft_strcmp(list->name, ".")
					!= 0 && ft_strcmp(list->name, "..") != 0)
			{
				l_list = ft_newele(ft_strdup(list->path));
				ft_putstr("\n");
				ft_putstr(l_list->name);
				ft_putstr(":\n");
				ft_ls(flag, l_list, 1, 0);
				ft_free_lst(&l_list);
			}
			list = list->next;
		}
	}
}
