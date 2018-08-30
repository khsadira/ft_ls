/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 10:30:16 by khsadira          #+#    #+#             */
/*   Updated: 2018/08/30 16:14:04 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define dir DIR
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include "./libft/libft.h"
# include <unistd.h>

#include <stdio.h> //a delete

int				main(int ac, char **av);
int				ft_nblen(int nb);
void			ft_put_off_t(off_t nb);

typedef struct	s_lst
{
	char			*name;
	
	struct stat		buf;
	char			socket;
	char			*right;
	int				link;
	char			*uid;
	char			*guid;
	long long int	b_size;
	int				i_time;
	char			*day;
	char			*hm;
	char			*month;
	char		*path;
	char		*n_link;
	long long int n_blocks;
	int		minor;
	int		major;
	struct s_lst	*next;
	struct s_lst	*bfr;
}					t_lst;

typedef struct s_flag
{
	int	a;
	int	t;
	int	r;
	int	R;
	int	l;
}		t_flag;

typedef struct	s_size
{
	int	s_size;
	int	s_uid;
	int	s_guid;
	int	s_block;
	int	s_day;
	int	s_hour;
	int	s_minor;
	int	s_major;
}				t_size;

int	major_d(unsigned int dev);
int	minor_d(int dev);
char	**ft_del_flag(char **str, int nb);
t_lst			*ft_addlist(t_lst *list, t_lst *new_ele);
t_lst			*convert_to_dir(int nb, char **str, t_flag *flag);
long long int	ft_blocks(t_lst *list);
t_size			*ft_format(t_lst *list);
t_flag			*convert_to_flag(char **str);
void			ft_ls(t_flag *flag, t_lst *rep, int ac, int nb_flag);
t_lst	*ft_make_list(DIR* dir, t_flag *flag, char *rep);
void	ft_lstprint(t_lst *list, t_flag *flag, t_size *size_l, long long int blocks);
t_lst	*ft_ls_l(char *rep, t_lst *list, t_flag *flag);
char	**ft_good_timer(char *str);
t_lst	*ft_list_sort(t_lst *list, t_flag *flag);
void	ft_ls_r(t_flag *flag, t_lst *list);
void	ft_error(int error_i, char *s);
t_lst	*ft_socket(struct stat buf, t_lst *list);
char	*ft_right(struct stat buf);
t_lst	*ft_empty_l(struct stat buf, t_lst *list);
t_lst	*ft_good_time(t_lst *list, char *time);
t_lst	*ft_good_time2(t_lst *list, char *time);
t_lst	*ft_newele(char *name);
char	**ft_sort_char(char **str, t_flag *flag);
t_lst	*merge_sort(t_lst *head);
t_lst	*merge_sort_t(t_lst *head);
char	**ft_check_ln(char **rep, t_flag *flag);
void	ft_lst_free(t_lst **list);
void	ft_putchar_socket(t_lst *list);
void	ft_putstr_right(t_lst *list);
#endif
