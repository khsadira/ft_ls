/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:37:47 by khsadira          #+#    #+#             */
/*   Updated: 2018/03/26 11:37:48 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t n)
{
	char	*ret;
	size_t	i;

	if (s != NULL)
	{
		if (!(ret = (char *)malloc(sizeof(*ret) * (n + 1))))
			return (NULL);
		i = 0;
		while (n--)
		{
			ret[i] = s[start];
			++i;
			++start;
		}
		ret[i] = '\0';
		return (ret);
	}
	return (NULL);
}
