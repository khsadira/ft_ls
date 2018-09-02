/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:15:40 by khsadira          #+#    #+#             */
/*   Updated: 2018/09/02 15:40:20 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_lstprint_l3(t_lst *list, t_size *size_l, time_t t1, char **date)
{
	int	i;

	ft_putstr(date[1]);
	i = 3 - ft_strlen(date[2]);
	while (i-- > 0)
		ft_putchar(' ');
	ft_putstr(date[2]);
	if (list->buf.st_mtime > t1 || list->buf.st_mtime > t1 - (262800 * 60))
	{
		date[3][5] = '\0';
		i = size_l->s_hour - ft_strlen(date[3]);
		while (i-- > 0)
			ft_putchar(' ');
		ft_putstr(date[3]);
	}
	else
	{
		date[4][ft_strlen(date[4]) - 1] = '\0';
		i = size_l->s_hour - ft_strlen(date[4]);
		while (i-- > 0)
			ft_putchar(' ');
		ft_putstr(date[4]);
	}
	ft_free_tab(&date);
	ft_putchar(' ');
}

static void	ft_lstprint_l21(t_lst *list, t_size *size_l, int phys)
{
	int	i;

	if (phys == 1)
	{
		i = 8 - ft_nblen(list->buf.st_size);
		while (i-- > 0)
			ft_putchar(' ');
		ft_put_off_t(list->buf.st_size);
	}
	else if (phys == 0)
	{
		i = size_l->s_block - ft_nblen(list->buf.st_size);
		while (i-- > 0)
			ft_putchar(' ');
		ft_put_off_t(list->buf.st_size);
	}
	ft_putchar(' ');
	ft_lstprint_l3(list, size_l, time(NULL),
			ft_strsplit(ctime(&(list->buf.st_mtime)), ' '));
}

static void	ft_lstprint_l2(t_lst *list, t_size *size_l, int phys)
{
	int	i;
	int	min;
	int	maj;

	if (phys == 1 && (S_ISCHR(list->buf.st_mode) || S_ISBLK(list->buf.st_mode)))
	{
		maj = major_d(list->buf.st_rdev);
		i = 1 + size_l->s_major - ft_nblen(maj);
		while (i-- > 0)
			ft_putchar(' ');
		ft_put_off_t(maj);
		ft_putchar(',');
		min = minor_d(list->buf.st_rdev);
		i = 4 - ft_nblen(min);
		while (i-- > 0)
			ft_putchar(' ');
		ft_put_off_t(min);
		ft_lstprint_l21(list, size_l, 2);
	}
	else
		ft_lstprint_l21(list, size_l, phys);
}

static void	ft_lstprint_l1(t_lst *list, t_size *size_l, int phys)
{
	struct group	*guid;
	int				i;

	if ((guid = getgrgid(list->buf.st_gid)))
	{
		i = 2 + size_l->s_guid - ft_strlen(guid->gr_name);
		ft_putstr(guid->gr_name);
	}
	else
	{
		i = 2 + size_l->s_guid - ft_nblen(list->buf.st_gid);
		ft_putnbr(list->buf.st_gid);
	}
	while (i-- > 0)
		ft_putchar(' ');
	ft_lstprint_l2(list, size_l, phys);
}

void		ft_lstprint_l(t_lst *list, t_size *size_l, int phys)
{
	struct passwd	*uid;
	int				i;

	ft_putchar_socket(list);
	ft_putstr_right(list);
	i = 2 + size_l->s_size - ft_nblen(list->buf.st_nlink);
	while (i-- > 0)
		ft_putchar(' ');
	ft_putnbr(list->buf.st_nlink);
	ft_putchar(' ');
	if ((uid = getpwuid(list->buf.st_uid)))
	{
		i = 2 + size_l->s_uid - ft_strlen(uid->pw_name);
		ft_putstr(uid->pw_name);
	}
	else
	{
		i = 2 + size_l->s_uid - ft_nblen(list->buf.st_uid);
		ft_putnbr(list->buf.st_uid);
	}
	while (i-- > 0)
		ft_putchar(' ');
	ft_lstprint_l1(list, size_l, phys);
}
