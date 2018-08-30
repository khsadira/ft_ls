/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:37:51 by khsadira          #+#    #+#             */
/*   Updated: 2018/03/26 11:37:52 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	char	*trim;
	size_t	start;
	size_t	len;

	if (s == NULL)
		return (NULL);
	start = 0;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		++start;
	if (!s[start])
	{
		if (!(trim = ft_strnew(1)))
			return (0);
		return (trim);
	}
	len = ft_strlen(s) - 1;
	while (s[len] == ' ' || s[len] == '\t' || s[len] == '\n')
		--len;
	len = len - start + 1;
	if (!(trim = ft_strnew(len)))
		return (NULL);
	if (!(trim = ft_strsub(s, start, len)))
		return (NULL);
	return (trim);
}
