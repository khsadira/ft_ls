/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:21:40 by khsadira          #+#    #+#             */
/*   Updated: 2018/06/26 17:19:03 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_size		*ft_init(t_size *size_l)
{
	if (!(size_l = (t_size *)malloc(sizeof(t_size))))
		return (NULL);
	size_l->s_size = 0;
	size_l->s_uid = 0;
	size_l->s_guid = 0;
	size_l->s_block = 0;
	size_l->s_day = 0;
	size_l->s_hour = 0;
	size_l->s_minor = 0;
	size_l->s_major = 0;
	return (size_l);
}
/*
static t_size		*ft_check_size2(t_size *size_l, t_lst *list)
{
	int		i;
	
	if (list->b_size)
		i = ft_nblen(list->b_size);
	else
		i = 0;
	if (size_l->s_block < i)
		size_l->s_block = i;
	if (list->day)
		i = ft_strlen(list->day);
	else
		i = 0;
	if (size_l->s_day < i)
		size_l->s_day = i;
	if (list->hm)
		i = ft_strlen(list->hm);
	else
		i = 0;
	if (size_l->s_hour < i)
		size_l->s_hour = i;
	i = ft_nblen(list->major);
	if (size_l->s_major < i)
		size_l->s_major = i;
	i = ft_nblen(list->minor);
	if (size_l->s_minor < i)
		size_l->s_minor = i;
	return (size_l);
}
*/
static t_size		*ft_check_size3(t_size *size_l, t_lst *list)
{
	int	i;

	if (S_ISCHR(list->buf.st_mode) || S_ISBLK(list->buf.st_mode))
	{
		i = 0;
		i = ft_nblen(minor_d(list->buf.st_rdev));
		if (size_l->s_minor < i)
			size_l->s_minor = i;
		i = 0;
		i = ft_nblen(major_d(list->buf.st_rdev));
		if (size_l->s_major < i)
			size_l->s_major = i;
	}
	return (size_l);
}

static t_size		*ft_check_size2(t_size *size_l, t_lst *list)
{
	int	i;
	time_t	t1;
	char	**date;
	char	*day;
	char	*month;
	char	*hm;
	
	date = ft_strsplit(ctime(&(list->buf.st_mtime)), ' ');
	//date[4][ft_strlen(date[4]) - 1] = '\0';
	//month = date[1];
	//day = date[2];
	//hm = date[4];
	//date[3][6] = '\0';
	//hm = date[3];
	t1 = time(NULL);
	i = ft_nblen(list->buf.st_size);
	free(date[0]);
	free(date[1]);
	if (size_l->s_block < i)
		size_l->s_block = i;
	i = ft_strlen(date[2]);
	free(date[2]);
	if (size_l->s_day < i)
		size_l->s_day = i;
	if (list->buf.st_mtime < t1 || list->buf.st_mtime > t1 - (262800 * 60))
	{
		date[3][6] = '\0';
		i = ft_strlen(date[3]);
		if (size_l->s_hour < i)
			size_l->s_hour = i;
	}
	else
	{
		date[4][ft_strlen(date[4]) - 1] = '\0';
		i = ft_strlen(date[4]);
		if (size_l->s_hour < i)
			size_l->s_hour = i;
	}
	free(date[3]);
	free(date[4]);
	free(date);
	return (ft_check_size3(size_l, list));
}

static t_size		*ft_check_size(t_size *size_l, t_lst *list)
{
	int	i;
	struct passwd	*uid;
	struct group	*guid;

	i = ft_nblen(list->buf.st_nlink);
	if (size_l->s_size < i)
		size_l->s_size = i;
	if ((uid = getpwuid(list->buf.st_uid)))
		i = ft_strlen(uid->pw_name);
	else
		i = ft_nblen(list->buf.st_uid);
	if (size_l->s_uid < i)
		size_l->s_uid = i;
	if ((guid = getgrgid(list->buf.st_gid)))
		i = ft_strlen(guid->gr_name);
	else
		i = ft_nblen(list->buf.st_gid);
	if (size_l->s_guid < i)
		size_l->s_guid = i;
	return (ft_check_size2(size_l, list));
}

/*
static t_size		*ft_check_size(t_size *size_l, t_lst *list)
{
	int		i;

	if (list->link)
		i = ft_nblen(list->link);
	else
		 i = 0;
	if (size_l->s_size < i)
		size_l->s_size = i;
	if (list->uid)
		i = ft_strlen(list->uid);
	if (size_l->s_uid < i)
		size_l->s_uid = i;
	if (list->guid)
		i = ft_strlen(list->guid);
	if (size_l->s_guid < i)
		size_l->s_guid = i;
	return (ft_check_size2(size_l, list));
}
*/

t_size				*ft_format(t_lst *list)
{
	t_size	*size_l;

	size_l = NULL;
	if (!(size_l = ft_init(size_l)))
		return (NULL);
	while (list)
	{
		size_l = ft_check_size(size_l, list);
		list = list->next;
	}
	return (size_l);
}