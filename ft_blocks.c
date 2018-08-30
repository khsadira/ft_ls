/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blocks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:34:15 by khsadira          #+#    #+#             */
/*   Updated: 2018/06/21 14:21:59 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long long int	ft_blocks(t_lst *list)
{
	long long int blocks;

	blocks = 0;
	while (list)
	{
		blocks += list->buf.st_blocks;
		list = list->next;
	}
	return (blocks);
}
