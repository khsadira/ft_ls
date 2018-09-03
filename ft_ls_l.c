/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:33:32 by khsadira          #+#    #+#             */
/*   Updated: 2018/09/03 15:35:13 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		*ft_path(char *rep, char *rep2)
{
	char	*ret;

	if (!(ret = ft_strnew(ft_strlen(rep) + ft_strlen(rep2) + 1)))
		return (NULL);
	ret = ft_strcat(ret, rep);
	if (!(ret[ft_strlen(ret) - 1] == '/'))
		ret = ft_strcat(ret, "/");
	ret = ft_strcat(ret, rep2);
	return ((ret));
}

t_lst			*ft_ls_l(char *rep, t_lst *list)
{
	struct stat	buf;

	if (!rep)
		list->path = ft_strdup(list->name);
	else if (!(list->path = ft_path(rep, list->name)))
		return (list);
	if (lstat(list->path, &buf))
	{
		ft_lst_free(&list);
		return (NULL);
	}
	list->buf = buf;
	return (list);
}
