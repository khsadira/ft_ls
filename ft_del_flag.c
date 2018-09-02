/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 13:48:08 by khsadira          #+#    #+#             */
/*   Updated: 2018/09/02 15:55:45 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	**ft_good_str(char **str, int i)
{
	int	j;

	j = 0;
	while (str[i])
		str[j++] = str[i++];
	while (str[j])
		str[j++] = 0;
	return (str);
}

char		**ft_del_flag(char **str, int nb)
{
	int		i;

	i = 1;
	while (str[i] && (str[i][0] == '-' && str[i][1] && str[i][1]))
	{
		if (str[i][1] == '-')
		{
			i++;
			break ;
		}
		i++;
	}
	if (i == nb)
	{
		str[0] = "./";
		i = 1;
		while (i < nb)
			str[i++] = 0;
		return (str);
	}
	return (ft_good_str(str, i));
}
