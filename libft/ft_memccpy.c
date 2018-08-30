/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:33:06 by khsadira          #+#    #+#             */
/*   Updated: 2018/03/26 11:33:07 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*ucptr1;
	char	*ucptr2;
	char	tmp;

	ucptr1 = (char *)dst;
	ucptr2 = (char *)src;
	tmp = (unsigned char)c;
	while (n--)
	{
		if ((*ucptr1++ = *ucptr2++) == tmp)
			return (ucptr1);
	}
	return (NULL);
}
