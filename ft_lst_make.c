/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_make.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:16:14 by khsadira          #+#    #+#             */
/*   Updated: 2018/06/26 17:18:18 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lst	*ft_addlist(t_lst *list, t_lst *new_ele)
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

t_lst			*ft_make_list(DIR *dir, t_flag *flag, char *rep)
{
	t_lst			*list;
	t_lst			*new_ele;
	struct dirent	*dirread;
	int		i = 0;

	new_ele = NULL;
	list = NULL;
	while ((dirread = readdir(dir)))
	{
		if (dirread->d_name[0] == '.' && flag->a == 1)
		{
			new_ele = ft_newele(ft_strdup(dirread->d_name));
			new_ele = ft_ls_l(rep, new_ele, flag);
			list = ft_addlist(list, new_ele);
		}
		else if (dirread->d_name[0] != '.')
		{
			new_ele = ft_newele(ft_strdup(dirread->d_name));
			new_ele = ft_ls_l(rep, new_ele, flag);
			list = ft_addlist(list, new_ele);
		}
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
