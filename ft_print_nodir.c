/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nodir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 10:28:06 by khsadira          #+#    #+#             */
/*   Updated: 2018/09/04 10:29:59 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_nodir(t_lst *list)
{
	while (list)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(list->name, 2);
		ft_putendl_fd(": No such file or directory", 2);
		list = list->next;
	}
}
