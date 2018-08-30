/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_ln.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 17:46:27 by khsadira          #+#    #+#             */
/*   Updated: 2018/06/26 17:46:43 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print_ln(t_lst *list, char *str)
{
	ft_putstr("  ");
	ft_putnbr(list->link);
	ft_putchar(' ');
	ft_putstr(list->uid);
	ft_putstr("  ");
	ft_putstr(list->guid);
	ft_putstr("  ");
	ft_putnbr((int)list->b_size);
	ft_putchar(' ');
	ft_putstr(list->month);
	ft_putchar(' ');
	ft_putstr(list->day);
	ft_putchar(' ');
	ft_putstr(list->hm);
	ft_putchar(' ');
	ft_putstr(list->name);
	if (str[0] != '\0')
	{
		ft_putstr(" -> ");
		ft_putstr(str);
	}
	ft_putchar(10);
}

static int	is_good_lnk(char *str)
{
	int		i;
	struct stat	buf;
	t_lst		*list;
	char		link[255];
	int		rl;

	link[0] = '\0';
	lstat(str, &buf);
	if (S_ISDIR(buf.st_mode))
		return (0);
	while (str[i] && str[i + 1])
		i++;


	i = 0;
	list = ft_newele(str);
	if (S_ISLNK(buf.st_mode))
		ft_putchar('l');
	else if (S_ISCHR(buf.st_mode))
		ft_putchar('c');
	else if (S_ISBLK(buf.st_mode))
		ft_putchar('b');
	else if (S_ISSOCK(buf.st_mode))
		ft_putchar('s');
	else if (S_ISREG(buf.st_mode))
		ft_putchar('-');
	ft_putstr(ft_right(buf));
	list = ft_empty_l(buf, list);
	rl = readlink(str, link, 255);
	link[rl] = '\0';
	ft_print_ln(list, link);
	return (1);

	return (0);
}

char	**ft_check_ln(char **rep, t_flag *flag)
{
	int		i;
	int		len;
	char		*tmp;
	int		dir;
	t_lst		*new_ele;
	t_lst		*list;

	dir = 0;
	len = 0;
	i = 0;
	new_ele = NULL;
	list = NULL;
	i = 0;
	while (rep[i])
	{
		new_ele = ft_newele(ft_strdup(rep[i]));
		new_ele = ft_ls_l(NULL, new_ele, flag);
		list = ft_addlist(list, new_ele);
		i++;
	}
	while (list && list->bfr)
		list = list->bfr;
	if (list && flag && flag->t == 1)
		list = merge_sort_t(list);
	else if (list)
		list = merge_sort(list);
	ft_lstprint(list, flag, ft_format(list), -1);
	if (list)
		ft_lst_free(&list);
	return (rep);
}
