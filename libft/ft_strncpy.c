/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:37:12 by khsadira          #+#    #+#             */
/*   Updated: 2018/03/26 11:37:13 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char	*cptr;

	cptr = dst;
	while (*src != '\0' && n > 0)
	{
		*cptr = *src;
		++cptr;
		++src;
		--n;
	}
	while (n--)
	{
		*cptr = '\0';
		++cptr;
	}
	return (dst);
}
