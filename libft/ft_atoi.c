/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:31:19 by khsadira          #+#    #+#             */
/*   Updated: 2018/05/24 15:29:53 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_atoi(const char *s)
{
	int		ret;
	int		sign;

	if (s == NULL)
		return (0);
	while (*s == ' ' || (*s >= '\t' && *s <= '\r'))
		++s;
	sign = 1;
	if (*s == '+')
		++s;
	else if (*s == '-')
	{
		++s;
		sign = -1;
	}
	ret = 0;
	while (*s >= '0' && *s <= '9')
	{
		ret = ret * 10 + *s - '0';
		++s;
	}
	return (ret * sign);
}
