/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:33:11 by khsadira          #+#    #+#             */
/*   Updated: 2018/03/26 11:33:11 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cptr;

	cptr = (unsigned char *)s;
	while (n--)
	{
		if (*cptr == (unsigned char)c)
			return ((void *)cptr);
		++cptr;
	}
	return (NULL);
}
