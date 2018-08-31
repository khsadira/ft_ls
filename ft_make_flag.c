/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:24:28 by khsadira          #+#    #+#             */
/*   Updated: 2018/08/31 14:07:51 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_flag	*init_flag(t_flag *flag)
{
	if (!(flag = (t_flag *)malloc(sizeof(t_flag))))
		return (NULL);
	flag->a = 0;
	flag->t = 0;
	flag->r = 0;
	flag->rec = 0;
	flag->l = 0;
	return (flag);
}

static void		flag_error(t_flag *flag)
{
	ft_putstr("ls: illegal option -- -\nusage: ls [-Ralrt] [file ...]\n");
	free(flag);
	exit(1);
}

static t_flag	*check_flag_error(t_flag *flag, char c)
{
	if (c == '-' || (c != 'a' && c != 't' &&
				c != 'r' && c != 'R' && c != 'l'))
		return (NULL);
	if (c == 'a')
		flag->a = 1;
	if (c == 't')
		flag->t = 1;
	if (c == 'r')
		flag->r = 1;
	if (c == 'R')
		flag->rec = 1;
	if (c == 'l')
		flag->l = 1;
	return (flag);
}

t_flag			*convert_to_flag(char **str)
{
	int			i;
	int			j;
	t_flag		*flag;

	flag = NULL;
	i = 1;
	if (!(flag = init_flag(flag)))
		return (NULL);
	while (str[i])
	{
		j = 1;
		if (str[i][0] != '-' || (str[i][0] == '-' && str[i][1] == '-' &&
					str[i][2] == '\0'))
			return (flag);
		while (str[i][j])
		{
			if (((flag = check_flag_error(flag, str[i][j])) == NULL))
				flag_error(flag);
			j++;
		}
		i++;
	}
	return (flag);
}
