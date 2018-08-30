/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:15:40 by khsadira          #+#    #+#             */
/*   Updated: 2018/08/30 16:19:08 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_lnk(t_lst *list)
{
	char	link[255];
	int	rl;

	rl = 0;
	if ((rl = readlink(list->path, link, 255)))
	{
		link[rl] = '\0';
		ft_putendl(link);
	}
}
/*
   static void	ft_lstprint_l(t_lst *list, t_size *size_l, int c)
   {
   int		i;

   i = 2;
   if (list->socket)
   ft_putchar(list->socket);
   if (list->right)
   ft_putstr(list->right);
   if (list->link)
   i = 2 + size_l->s_size - ft_nblen(list->link);
   while (i > 0)
   {
   ft_putchar(' ');
   i--;
   }
   if (list->link)
   ft_putnbr(list->link);	
   ft_putchar(' ');
   if (list->uid)
   i = 2 + size_l->s_uid - ft_strlen(list->uid);
   else
   i = 2 + size_l->s_uid;
   if (list->uid)
   ft_putstr(list->uid);
   while (i > 0)
   {
   ft_putchar(' ');
   i--;
   }
   if (list->guid)
   i = 2 + size_l->s_guid - ft_strlen(list->guid);
   else
   i = 2 + size_l->s_guid;
   if (list->guid)
   ft_putstr(list->guid);
   while (i > 0)
   {
   ft_putchar(' ');
   i--;
   }
   if ((list->socket == 'c'  || list->socket == 'b'))
   {
   i = size_l->s_major - ft_nblen(list->major) + 1;
   while (i > 0)
   {
   ft_putchar(' ');
   i--;
   }
   ft_putnbr(list->major);
   ft_putchar(',');
   i = size_l->s_minor - ft_nblen(list->minor) + 1;
   while (i > 0)
   {
   ft_putchar(' ');
   i--;
   }
   ft_putnbr(list->minor);
   }
   else
   {
   if (c == 1)
   {
   i = size_l->s_major + size_l->s_minor + 1;
   while (i > 0)
   {
   ft_putchar(' ');
   i--;
   }
   }
i = size_l->s_block - ft_nblen(list->b_size) + 1;
while (i > 0)
{
	ft_putchar(' ');
	i--;
}
ft_putnbr((int)list->b_size);
}
ft_putchar(' ');
if (list->month)
	ft_putstr(list->month);
if (list->day)
	i = 1 + size_l->s_day - ft_strlen(list->day);
	else
	i = 1 + size_l->s_day;
while (i > 0)
{
	ft_putchar(' ');
	i--;
}
if (list->day)
	ft_putstr(list->day);
if (list->hm)
	i = 1 + size_l->s_hour - ft_strlen(list->hm);
	else
	i = 1 + size_l->s_hour;
while (i > 0)
{
	ft_putchar(' ');
	i--;
}
if (list->hm)
	ft_putstr(list->hm);
	ft_putchar(' ');
	}*/

static int	ft_phys(t_lst *list)
{
	while (list)
	{
		if (S_ISCHR(list->buf.st_mode) || S_ISBLK(list->buf.st_mode))
			return (1);
		list = list->next;
	}
	return (0);
}

static void	ft_lstprint_l3(t_lst *list, t_size *size_l)
{
	time_t	t1;
	int	i;
	char	**date;

	t1 = time(NULL);
	date = ft_strsplit(ctime(&(list->buf.st_mtime)), ' ');
	ft_putchar(' ');
	ft_putstr(date[1]);
	i = 1 + size_l->s_day - ft_strlen(date[2]);
	while (i-- > 0)
		ft_putchar(' ');
	ft_putstr(date[2]);
	if (list->buf.st_mtime < t1 || list->buf.st_mtime > t1 - (262800 * 60))
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
	free(date[0]);
	free(date[1]);
	free(date[2]);
	free(date[3]);
	free(date[4]);
	free(date);
	ft_putchar(' ');
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
		ft_putnbr(maj);
		ft_putchar(',');
		min = minor_d(list->buf.st_rdev);
		i = size_l->s_minor - ft_nblen(min);
		while (i-- > 0)
			ft_putchar(' ');
		ft_putnbr(min);
	}
	else
	{
		if (phys == 1)
		{
			i = 1 + size_l->s_minor + size_l->s_major;
			while (i--)
				ft_putchar(' ');
		}
		i = size_l->s_block - ft_nblen(list->buf.st_size);
		while (i-- > 0)
			ft_putchar(' ');
		ft_put_off_t(list->buf.st_size);
	}
	ft_lstprint_l3(list, size_l);
}

static void	ft_lstprint_l(t_lst *list, t_size *size_l, int phys)
{
	struct passwd	*uid;
	struct group	*guid;
	int		i;

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

void	ft_lstprint(t_lst *list, t_flag *flag, t_size *size_l, long long int blocks)
{
	int		i;

	i = 0;
	if (flag && flag->l == 1 && blocks != -1 && list)
	{
		ft_putstr("total ");
		ft_putnbrendl((int)blocks);
	}
	if (flag && flag->r == 1)
	{
		while (list && list->next)
			list = list->next;
		while (list)
		{
			if (flag && flag->l == 1)
			{
				ft_lstprint_l(list, size_l, ft_phys(list));
				if (S_ISLNK(list->buf.st_mode))
				{
					ft_putstr(list->name);
					ft_putstr(" -> ");
					ft_lnk(list);
				}
				else
					ft_putendl(list->name);
			}
			else
				ft_putendl(list->name);
			list = list->bfr;
		}
	}
	else
	{
		while (list)
		{
			if (flag && flag->l == 1)
			{
				ft_lstprint_l(list, size_l, ft_phys(list));
				if (S_ISLNK(list->buf.st_mode))
				{
					ft_putstr(list->name);
					ft_putstr(" -> ");
					ft_lnk(list);
				}
				else
					ft_putendl(list->name);
			}
			else
				ft_putendl(list->name);
			list = list->next;
		}
	}
}
