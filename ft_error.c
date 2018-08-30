/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:30:32 by khsadira          #+#    #+#             */
/*   Updated: 2018/06/26 17:12:27 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(int error_i, char *s)
{
	if (errno == 2)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(s, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else if (errno == EACCES)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(s, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	else if (errno == ENOTDIR)
		ft_putendl_fd(s, 2);
}
