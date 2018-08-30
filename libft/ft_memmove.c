/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:33:31 by khsadira          #+#    #+#             */
/*   Updated: 2018/03/26 11:33:31 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*cptr1;
	unsigned char	*cptr2;

	cptr1 = (unsigned char *)dst;
	cptr2 = (unsigned char *)src;
	if (cptr1 < cptr2)
		return (ft_memcpy(dst, src, n));
	cptr1 += n - 1;
	cptr2 += n - 1;
	while (n--)
		*cptr1-- = *cptr2--;
	return (dst);
}
