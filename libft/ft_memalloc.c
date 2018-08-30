/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 11:33:00 by khsadira          #+#    #+#             */
/*   Updated: 2018/03/26 11:33:01 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t n)
{
	char	*ret;

	if (!(ret = (char *)malloc(sizeof(*ret) * n)))
		return (NULL);
	ft_bzero(ret, n);
	return (ret);
}
