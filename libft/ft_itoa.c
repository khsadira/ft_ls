/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:32:20 by khsadira          #+#    #+#             */
/*   Updated: 2018/03/26 11:32:20 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_itoa(int n)
{
	char	*ret;
	int		tmp;
	int		len;

	tmp = n;
	len = 1;
	if (n < 0)
		len += 1;
	while ((tmp /= 10))
		len += 1;
	tmp = n;
	if (!(ret = (char *)malloc(sizeof(*ret) * (len + 1))))
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		n = -n;
	ret[len--] = '\0';
	while (len >= 0)
	{
		ret[len--] = n % 10 + '0';
		n /= 10;
	}
	ret[0] = (tmp < 0) ? '-' : ret[0];
	return (ret);
}
