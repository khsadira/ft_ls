/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:33:32 by khsadira          #+#    #+#             */
/*   Updated: 2018/06/21 14:31:35 by khsadira         ###   ########.fr       */
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

static t_lst	*ft_ls_l_0(t_lst *list)
{
	list->socket = 0;
	list->right = 0;
	list->link = 0;
	list->uid = 0;
	list->guid = 0;
	list->i_time = 0;
	list->day = 0;
	list->hm = 0;
	list->month = 0;
	list->path = 0;
	list->n_link = 0;
	list->n_blocks = 0;
	list->b_size = 0;
	list->major = 0;
	list->minor = 0;
	return (list);
}

/*t_lst			*ft_ls_l(char *rep, t_lst *list,
					t_flag *flag)
{
	struct stat	buf;

	list = ft_ls_l_0(list);
	if (!rep)
		list->path = ft_strdup(list->name);
	else if (!(list->path = ft_path(rep, list->name)))
		return (list);
	if (lstat(list->path, &buf) == -1)
		return (list);
	if (flag && (flag->R == 1 || flag->l == 1))
		list = ft_socket(buf, list);
	if (flag && (flag->l == 1))
		list->right = ft_right(buf);
	if (flag && (flag->t == 1 || flag->l == 1))
		list->i_time = buf.st_mtime;
	if (flag && flag->l == 0)
		return (list);
	list = ft_empty_l(buf, list);
	return (list);
}*/

t_lst		*ft_ls_l(char *rep, t_lst *list, t_flag *flag)
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
