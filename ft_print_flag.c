/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 19:52:55 by khsadira          #+#    #+#             */
/*   Updated: 2018/09/01 20:47:32 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_size		*ft_init(t_size *size_l)
{
	if (!(size_l = (t_size *)malloc(sizeof(t_size))))
		return (NULL);
	size_l->s_ino = 0;
	size_l->s_blocks = 0;
	return (size_l);
}

t_size				*ft_format_spec(t_flag *flag, t_size *size_l, t_lst *list)
{
	int	i;

	size_l = ft_init(size_l);
	i = 0;
	if (flag->i == 0 && flag->s == 0)
		return (NULL);
	while (list)
	{
		if (flag->i == 1)
		{
			i = ft_nblen(list->buf.st_ino);
			if (size_l->s_ino < i)
				size_l->s_ino = i;
		}
		if (flag->s == 1)
		{
			i = ft_nblen(list->buf.st_blocks);
			if (size_l->s_blocks < i)
				size_l->s_blocks = i;
		}
		list = list->next;
	}
	return (size_l);
}

void				ft_print_flag(t_flag *flag, t_size *size, t_lst *list)
{
	int		i;

	i = 0;
	if (flag->i == 1)
	{
		i = size->s_ino - ft_nblen(list->buf.st_ino);
		while (i--)
			ft_putchar(' ');
		ft_put_off_t(list->buf.st_ino);
		ft_putchar(' ');
	}
	if (flag->s == 1)
	{
		i = size->s_blocks - ft_nblen(list->buf.st_blocks);
		while (i--)
			ft_putchar(' ');
		ft_put_off_t(list->buf.st_blocks);
		ft_putchar(' ');
	}
}
