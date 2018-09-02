/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:04:47 by khsadira          #+#    #+#             */
/*   Updated: 2018/09/02 16:56:35 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_putchar_socket(t_lst *list)
{
	if (S_ISLNK(list->buf.st_mode))
		ft_putchar('l');
	if (S_ISDIR(list->buf.st_mode))
		ft_putchar('d');
	if (S_ISCHR(list->buf.st_mode))
		ft_putchar('c');
	if (S_ISBLK(list->buf.st_mode))
		ft_putchar('b');
	if (S_ISSOCK(list->buf.st_mode))
		ft_putchar('s');
	if (S_ISREG(list->buf.st_mode))
		ft_putchar('-');
}

static void	ft_putstr_right2(t_lst *list)
{
	if (S_ISGID & list->buf.st_mode)
	{
		if (list->buf.st_mode & S_IXGRP)
			ft_putchar('S');
		else
			ft_putchar('s');
	}
	else
		(list->buf.st_mode & S_IXGRP) == S_IXGRP ?
			(ft_putchar('x')) : (ft_putchar('-'));
	(list->buf.st_mode & S_IROTH) == S_IROTH ?
		(ft_putchar('r')) : (ft_putchar('-'));
	(list->buf.st_mode & S_IWOTH) == S_IWOTH ?
		(ft_putchar('w')) : (ft_putchar('-'));
	if (S_ISVTX & list->buf.st_mode)
	{
		if (list->buf.st_mode & S_IXOTH)
			ft_putchar('t');
		else
			ft_putchar('T');
	}
	else
		(list->buf.st_mode & S_IXOTH) == S_IXOTH ?
			(ft_putchar('x')) : (ft_putchar('-'));
}

void		ft_putstr_right(t_lst *list)
{
	(list->buf.st_mode & S_IRUSR) == S_IRUSR ?
		(ft_putchar('r')) : (ft_putchar('-'));
	(list->buf.st_mode & S_IWUSR) == S_IWUSR ?
		(ft_putchar('w')) : (ft_putchar('-'));
	if (S_ISUID & list->buf.st_mode)
	{
		if (list->buf.st_mode & S_IXUSR)
			ft_putchar('S');
		else
			ft_putchar('s');
	}
	else
		(list->buf.st_mode & S_IXUSR) == S_IXUSR ?
			(ft_putchar('x')) : (ft_putchar('-'));
	(list->buf.st_mode & S_IRGRP) == S_IRGRP ?
		(ft_putchar('r')) : (ft_putchar('-'));
	(list->buf.st_mode & S_IWGRP) == S_IWGRP ?
		(ft_putchar('w')) : (ft_putchar('-'));
	ft_putstr_right2(list);
}
