/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 16:23:47 by khsadira          #+#    #+#             */
/*   Updated: 2018/09/03 10:59:20 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_print_color(t_lst *list)
{
	if (S_ISDIR(list->buf.st_mode))
		ft_putstr(B_CYAN);
	else if (S_ISLNK(list->buf.st_mode))
		ft_putstr(PURPLE);
	else if (S_ISFIFO(list->buf.st_mode))
		ft_putstr(YELLOW);
	else if (S_ISREG(list->buf.st_mode) &&
		((list->buf.st_mode & S_IXUSR) == S_IXUSR))
		ft_putstr(RED);
	ft_putstr(list->name);
	ft_putstr(INIT);
}
