/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stat1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 15:40:05 by khsadira          #+#    #+#             */
/*   Updated: 2018/08/31 12:19:25 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	major_d(unsigned int dev)
{
	int		res;

	res = dev >> 24 & 0xff;
	return (res);
}

int	minor_d(int dev)
{
	int		res;

	res = dev & 0xffffff;
	return (res);
}
