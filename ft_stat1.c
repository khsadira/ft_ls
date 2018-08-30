/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stat1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 15:40:05 by khsadira          #+#    #+#             */
/*   Updated: 2018/06/19 16:49:19 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_lst	*ft_socket(struct stat buf, t_lst *list)
{
	char	link[255];
	int		rl;

	rl = 0;
	list->n_link = NULL;
	if (S_ISLNK(buf.st_mode))
	{
		list->socket = 'l';
		if ((rl = readlink(list->path, link, 255)))
		{
			link[rl] = '\0';
			list->n_link = ft_strdup(link);
		}
	}
	else if (S_ISDIR(buf.st_mode)) list->socket = 'd';
	else if (S_ISCHR(buf.st_mode)) list->socket = 'c';
	else if (S_ISBLK(buf.st_mode)) list->socket = 'b';
	else if (S_ISSOCK(buf.st_mode)) list->socket = 's';
	else if (S_ISREG(buf.st_mode)) list->socket = '-';
	return (list);
}

char	*ft_right(struct stat buf)
{
	char	*str;

	str = ft_strnew(10);
	(buf.st_mode & S_IRUSR) == S_IRUSR ? (str[0] = 'r') : (str[0] = '-');
	(buf.st_mode & S_IWUSR) == S_IWUSR ? (str[1] = 'w') : (str[1] = '-');
	(buf.st_mode & S_IXUSR) == S_IXUSR ? (str[2] = 'x') : (str[2] = '-');
	(buf.st_mode & S_IRGRP) == S_IRGRP ? (str[3] = 'r') : (str[3] = '-');
	(buf.st_mode & S_IWGRP) == S_IWGRP ? (str[4] = 'w') : (str[4] = '-');
	(buf.st_mode & S_IXGRP) == S_IXGRP ? (str[5] = 'x') : (str[5] = '-');
	(buf.st_mode & S_IROTH) == S_IROTH ? (str[6] = 'r') : (str[6] = '-');
	(buf.st_mode & S_IWOTH) == S_IWOTH ? (str[7] = 'w') : (str[7] = '-');
	(buf.st_mode & S_IXOTH) == S_IXOTH ? (str[8] = 'x') : (str[8] = '-');
	return (str);
}

int	major_d(unsigned int dev)
{
	int		res;

	res = dev >> 24 & 0xff;
	return (res);
}

int	minor_d(int dev)
{
	int		res;

	res = dev & 0xffffff;
	return (res);
}

t_lst *ft_empty_l(struct stat buf, t_lst *list)
{
	struct passwd	*uid;
	struct group	*guid;
	time_t			t1;
	struct stat buf2;

	t1 = time(NULL);
	list->n_blocks = buf.st_blocks;
	if (list->i_time > t1 || list->i_time < t1 - (262800 * 60))
		list = ft_good_time2(list, ctime(&(buf.st_mtime)));
	else
		list = ft_good_time(list, ctime(&(buf.st_mtime)));
	list->link = buf.st_nlink;
	if ((uid = getpwuid(buf.st_uid)))
		list->uid = ft_strdup(uid->pw_name);
	if ((guid = getgrgid(buf.st_gid)))
		list->guid = ft_strdup(guid->gr_name);
	else
		list->guid = ft_strdup("");
	if ((list->socket == 'c' || list->socket == 'b'))
	{
		stat(list->path, &buf2);
		list->minor = minor_d(buf2.st_rdev);
		list->major = major_d(buf2.st_rdev);
	}
	list->b_size = buf.st_size;
	return (list);
}
