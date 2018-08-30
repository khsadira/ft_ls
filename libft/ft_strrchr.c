/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:37:32 by khsadira          #+#    #+#             */
/*   Updated: 2018/03/26 11:37:32 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*end;

	end = (char*)s + ft_strlen(s);
	while (end >= (char*)s)
	{
		if (*end == (char)c)
			return ((char *)end);
		--end;
	}
	return (NULL);
}
