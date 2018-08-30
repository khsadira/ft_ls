/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:36:50 by khsadira          #+#    #+#             */
/*   Updated: 2018/03/26 11:36:51 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	size_t	i;

	if (s != NULL && f != NULL)
	{
		if (!(ret = (char *)malloc(sizeof(*ret) * (ft_strlen(s) + 1))))
			return (NULL);
		i = 0;
		while (s[i])
		{
			ret[i] = (*f)(s[i]);
			++i;
		}
		ret[i] = '\0';
		return (ret);
	}
	return (NULL);
}
