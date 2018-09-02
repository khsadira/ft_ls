/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aclattr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/02 16:55:13 by khsadira          #+#    #+#             */
/*   Updated: 2018/09/02 19:06:22 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	get_acl(char *path)
{
	acl_t		acl;
	acl_entry_t	acl_ent;

	acl = NULL;
	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &acl_ent) == -1)
	{
		ft_putendl(path);
		acl_free((void *)acl);
		acl = NULL;
	}
	if (acl)
	{
		ft_putchar('+');
		return (1);
	}
	return (0);
}

static int	ft_diropen(t_lst *list)
{
	DIR	*dir;

	dir = NULL;
	if (S_ISDIR(list->buf.st_mode) && !(dir = opendir(list->path)))
		return (0);
	if (S_ISDIR(list->buf.st_mode) && closedir(dir) == -1)
	{
		ft_error(list->name);
		return (0);
	}
	return (1);
}

int			ft_aclattr(t_lst *list)
{
	char	link[255];
	int		rl;
	DIR		*dir;

	rl = 0;
	dir = NULL;
	if (!ft_diropen(list))
		return (0);
	if (S_ISLNK(list->buf.st_mode))
	{
		if ((rl = readlink(list->path, link, 255)))
			link[rl] = '\0';
		if (get_acl(list->path))
			return (1);
		if (listxattr(link, NULL, 0, XATTR_NOFOLLOW) != 0)
		{
			ft_putchar('@');
			return (1);
		}
	}
	if (listxattr(list->path, NULL, 0, XATTR_NOFOLLOW) != 0)
	{
		ft_putchar('@');
		return (1);
	}
	if (get_acl(list->path))
		return (1);
	return (0);
}
