/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:37:43 by khsadira          #+#    #+#             */
/*   Updated: 2018/03/26 11:37:44 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *h, const char *n)
{
	size_t	i;
	size_t	j;

	if (!*n)
		return ((char *)h);
	i = 0;
	while (h[i])
	{
		j = 0;
		while (h[i + j] == n[j] && n[j])
			++j;
		if (!n[j])
			return ((char *)(h + i));
		++i;
	}
	return (NULL);
}
