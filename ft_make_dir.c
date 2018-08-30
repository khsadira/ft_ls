/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:25:26 by khsadira          #+#    #+#             */
/*   Updated: 2018/08/30 17:22:33 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	**ft_good_str(char **str, int i)
{
	int	j;

	j = 0;
	while (str[i])
		str[j++] = str[i++];
	while (str[j])
		str[j++] = 0;
	return (str);
}

char		**ft_del_flag(char **str, int nb)
{
	int		i;
	int		j;

	i = 1;
	while (str[i] && (str[i][0] == '-' && str[i][1] && str[i][1]))
	{
		if (str[i][1] == '-')
		{
			i++;
			break ;
		}
		i++;
	}
	if (i == nb)
	{
		str[0] = "./";
		i = 1;
		while (i < nb)
			str[i++] = 0;
		return (str);
	}
	return (ft_good_str(str, i));
}

static t_lst	*l_noexist(char **str)
{
	int			i;
	t_lst		*new_ele;
	t_lst		*list;
	struct stat	buf;

	list = NULL;
	i = 0;
	while (str[i])
	{
		if (lstat(str[i], &buf) == -1 && errno == 2)
		{
			new_ele = ft_newele(ft_strdup(str[i]));
			list = ft_addlist(list, new_ele);
		}
		i++;
	}
	while (list && list->bfr)
		list = list->bfr;
	return (list);
}

static t_lst	*l_rep(char **str, t_flag *flag)
{
	int			i;
	t_lst		*new_ele;
	t_lst		*list;
	struct stat	buf;

	list = NULL;
	i = 0;
	while (str[i])
	{
		if (lstat(str[i], &buf) != -1 && S_ISDIR(buf.st_mode))
		{
			new_ele = ft_newele(ft_strdup(str[i]));
			new_ele = ft_ls_l(NULL, new_ele, flag);
			list = ft_addlist(list, new_ele);
		}
		i++;
	}
	while (list && list->bfr)
		list = list->bfr;
	return (list);
}

static t_lst	*l_file(char **str, t_flag *flag)
{
	int			i;
	t_lst		*new_ele;
	t_lst		*list;
	struct stat	buf;

	new_ele = NULL;
	list = NULL;
	i = 0;
	while (str[i])
	{
		if (lstat(str[i], &buf) != -1 && !S_ISDIR(buf.st_mode))
		{
			new_ele = ft_newele(ft_strdup(str[i]));
			new_ele = ft_ls_l(NULL, new_ele, flag);
			list = ft_addlist(list, new_ele);
		}
		i++;
	}
	while (list && list->bfr)
		list = list->bfr;
	return (list);
}
t_lst	*convert_to_dir(int nb, char **str, t_flag *flag)
{
	t_lst	*rep;
	t_lst	*file;
	t_lst	*noexist;
	t_size	*form;

	str = ft_del_flag(str, nb);
	noexist = merge_sort(l_noexist(str));
	if (noexist)
	{
		while (noexist)
		{
			ft_putstr_fd("ft_ls: ", 2);
			ft_putstr_fd(noexist->name, 2);
			ft_putstr_fd(": No such file or directory\n", 2);
			noexist = noexist->next;
		}
		ft_lst_free(&noexist);
	}
	file = l_file(str, flag);
	if (flag && flag->t == 1)
		rep = merge_sort_t(l_rep(str, flag));
	else
		rep = merge_sort(l_rep(str, flag));
	if (file)
	{
		if (flag && flag->t == 1)
			file = merge_sort_t(file);
		else
			file = merge_sort(file);
		if (flag->l == 1)
			form = ft_format(file);
		ft_lstprint(file, flag, form, -1);
		if (rep)
			ft_putchar(10);
		ft_lst_free(&file);
		if (flag->l == 1)
			free(form);
	}
	return (rep);
}
