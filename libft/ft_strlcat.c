/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:36:38 by khsadira          #+#    #+#             */
/*   Updated: 2018/03/26 11:36:39 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(dst) + ft_strlen(src);
	i = 0;
	while (dst[i] && i < n)
		++i;
	if (i == n)
		return (i + ft_strlen(src));
	j = 0;
	while (src[j] && i + j < n - 1)
	{
		dst[i + j] = src[j];
		++j;
	}
	dst[i + j] = '\0';
	return (len);
}
