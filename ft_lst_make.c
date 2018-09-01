/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_make.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:16:14 by khsadira          #+#    #+#             */
/*   Updated: 2018/09/01 19:46:33 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lst			*ft_addlist(t_lst *list, t_lst *new_ele)
{
	if (new_ele == NULL)
		return (list);
	if (list == NULL)
		return (new_ele);
	while (list->next)
		list = list->next;
	new_ele->bfr = list;
	list->next = new_ele;
	return (list);
}

t_lst			*ft_newele(char *name)
{
	t_lst	*list;

	if (!(list = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	list->name = name;
	list->bfr = NULL;
	list->next = NULL;
	return (list);
}

static t_lst	*ft_creatlist(char *name, char *rep, t_flag *flag, t_lst *list)
{
	t_lst	*new_ele;

	new_ele = NULL;
	new_ele = ft_newele(name);
	new_ele = ft_ls_l(rep, new_ele, flag);
	list = ft_addlist(list, new_ele);
	return (list);
}

static int		ft_check_a(t_flag *flag, char *name)
{
	if (flag->a == 0 && flag->alm == 1 && name[0] == '.' &&
			!ft_strequ(name, ".") && !ft_strequ(name, ".."))
		return (1);
	return (0);
}

t_lst			*ft_make_list(DIR *dir, t_flag *flag, char *rep)
{
	t_lst			*list;
	t_lst			*new_ele;
	struct dirent	*dirread;
	int				i;

	i = 0;
	new_ele = NULL;
	list = NULL;
	while ((dirread = readdir(dir)))
	{
		if (ft_check_a(flag, dirread->d_name))
			list = ft_creatlist(ft_strdup(dirread->d_name), rep, flag, list);
		else if (dirread->d_name[0] == '.' && flag->a == 1)
			list = ft_creatlist(ft_strdup(dirread->d_name), rep, flag, list);
		else if (dirread->d_name[0] != '.')
			list = ft_creatlist(ft_strdup(dirread->d_name), rep, flag, list);
		i++;
	}
	while (list && list->bfr)
		list = list->bfr;
	if (list && flag && flag->t == 1)
		list = merge_sort_t(list);
	else if (list)
		list = merge_sort(list);
	return (list);
}
