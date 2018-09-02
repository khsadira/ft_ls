/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:15:40 by khsadira          #+#    #+#             */
/*   Updated: 2018/09/02 18:17:43 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_f(t_lst *list, int flag, int put)
{
	ft_print_color(list);
	if (flag == 1)
	{
		if (S_ISDIR(list->buf.st_mode))
			ft_putchar('/');
		else if (S_ISLNK(list->buf.st_mode))
			ft_putchar('@');
		else if (S_ISFIFO(list->buf.st_mode))
			ft_putchar('|');
		else if (S_ISREG(list->buf.st_mode) && list->buf.st_mode & S_IXUSR)
			ft_putchar('*');
	}
	if (put)
		ft_putchar(10);
}

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

static void	ft_lstprint_r(t_lst *list, t_flag *flag, t_size *size_l)
{
	int		phys;
	t_size	*size;

	size = NULL;
	size = ft_format_spec(flag, size, list);
	phys = ft_phys(list);
	while (list && list->next)
		list = list->next;
	while (list)
	{
		ft_print_flag(flag, size, list);
		if (flag && flag->l == 1)
		{
			ft_lstprint_l(list, size_l, phys);
			if (S_ISLNK(list->buf.st_mode))
				ft_print_ln(list, flag->fi);
			else
				ft_print_f(list, flag->fi, 1);
		}
		else
			ft_print_f(list, flag->fi, 1);
		list = list->bfr;
	}
	free(size);
}

static void	ft_lstprint_norm(t_lst *list, t_flag *flag, t_size *size_l)
{
	int		phys;
	t_size	*size;

	size = NULL;
	size = ft_format_spec(flag, size, list);
	phys = ft_phys(list);
	while (list)
	{
		ft_print_flag(flag, size, list);
		if (flag && flag->l == 1)
		{
			ft_lstprint_l(list, size_l, phys);
			if (S_ISLNK(list->buf.st_mode))
				ft_print_ln(list, flag->fi);
			else
				ft_print_f(list, flag->fi, 1);
		}
		else
			ft_print_f(list, flag->fi, 1);
		list = list->next;
	}
	free(size);
}

void		ft_lstprint(t_lst *list, t_flag *flag,
			t_size *size_l, long long int blocks)
{
	int	i;
	int	phys;

	phys = ft_phys(list);
	i = 0;
	if (flag && (flag->l || flag->s) && blocks != -1 && list)
	{
		ft_putstr("total ");
		ft_put_off_t(blocks);
		ft_putendl("");
	}
	if (flag && flag->r == 1 && flag->f == 0)
		ft_lstprint_r(list, flag, size_l);
	else
		ft_lstprint_norm(list, flag, size_l);
}
