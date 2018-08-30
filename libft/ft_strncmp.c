/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:37:05 by khsadira          #+#    #+#             */
/*   Updated: 2018/03/26 11:37:06 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*cptr1;
	unsigned char	*cptr2;

	cptr1 = (unsigned char *)s1;
	cptr2 = (unsigned char *)s2;
	while (n--)
	{
		if (*cptr1 != *cptr2 || *cptr1 == '\0' || *cptr2 == '\0')
			return (*cptr1 - *cptr2);
		++cptr1;
		++cptr2;
	}
	return (0);
}