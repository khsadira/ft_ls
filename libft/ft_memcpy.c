/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:33:20 by khsadira          #+#    #+#             */
/*   Updated: 2018/03/26 11:33:21 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ucptr1;
	unsigned char	*ucptr2;

	ucptr1 = (unsigned char *)dst;
	ucptr2 = (unsigned char *)src;
	while (n--)
		*ucptr1++ = *ucptr2++;
	return (dst);
}
