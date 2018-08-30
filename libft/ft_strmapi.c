/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:36:56 by khsadira          #+#    #+#             */
/*   Updated: 2018/03/26 11:36:57 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	i;

	ret = NULL;
	if (s != NULL && f != NULL)
	{
		if (!(ret = (char *)malloc(sizeof(*ret) * (ft_strlen(s) + 1))))
			return (NULL);
		i = 0;
		while (s[i])
		{
			ret[i] = (*f)(i, (char)s[i]);
			++i;
		}
		ret[i] = '\0';
	}
	return (ret);
}
