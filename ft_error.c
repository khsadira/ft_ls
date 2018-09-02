/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:30:32 by khsadira          #+#    #+#             */
/*   Updated: 2018/09/02 15:54:45 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_start_to_file(char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (i > 0 && s[i] != '/')
		i--;
	if (s[i] && s[i] == '/')
		i++;
	return (i);
}

void		ft_error(char *s)
{
	int	i;

	i = ft_start_to_file(s);
	if (errno == 2)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(s + i, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else if (errno == EACCES)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(s + i, 2);
		ft_putstr_fd(": Permission denied\n", 2);
	}
	else if (errno == ENOTDIR)
		ft_putendl_fd(s + i, 2);
}
