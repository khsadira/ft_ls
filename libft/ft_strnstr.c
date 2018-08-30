/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:37:27 by khsadira          #+#    #+#             */
/*   Updated: 2018/03/26 11:37:28 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*n)
		return (char *)h;
	i = 0;
	while (h[i] && i < len)
	{
		j = 0;
		while (h[i + j] == n[j] && n[j] && i + j < len)
			++j;
		if (!n[j])
			return (char *)(h + i);
		++i;
	}
	return (NULL);
}
