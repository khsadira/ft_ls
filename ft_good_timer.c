/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_good_timer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 16:41:57 by khsadira          #+#    #+#             */
/*   Updated: 2018/06/21 14:28:07 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lst		*ft_good_time(t_lst *list, char *time)
{
	char	**date;

	date = ft_strsplit(time, ' ');
	list->month = ft_strdup(date[1]);
	list->day = ft_strdup(date[2]);
	list->hm = ft_strsub(date[3], 0, 5);
	return (list);
}

t_lst		*ft_good_time2(t_lst *list, char *time)
{
	char	**date;

	date = ft_strsplit(time, ' ');
	date[4][ft_strlen(date[4]) - 1] = '\0';
	list->month = ft_strdup(date[1]);
	list->day = ft_strdup(date[2]);
	list->hm = ft_strdup(date[4]);
	return (list);
}
