/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 10:30:16 by khsadira          #+#    #+#             */
/*   Updated: 2018/09/04 13:40:58 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include "./libft/libft.h"
# include "ft_color.h"
# include <unistd.h>

typedef struct		s_lst
{
	char			*name;
	struct stat		buf;
	char			*path;
	int				minor;
	int				major;
	struct s_lst	*next;
	struct s_lst	*bfr;
}					t_lst;

typedef struct		s_flag
{
	int	a;
	int	t;
	int	r;
	int	rec;
	int	l;
	int	alm;
	int	s;
	int	i;
	int	fi;
	int	f;
}					t_flag;

typedef struct		s_size
{
	int	s_size;
	int	s_uid;
	int	s_guid;
	int	s_block;
	int	s_day;
	int	s_hour;
	int	s_minor;
	int	s_major;
	int	s_ino;
	int	s_blocks;
}					t_size;

int					main(int ac, char **av);
int					ft_nblen(int nb);
void				ft_put_off_t(off_t nb);
void				ft_free_tab(char ***tab);
void				ft_lstprint_l(t_lst *list, t_size *size_l, int phys);
int					major_d(unsigned int dev);
int					minor_d(int dev);
char				**ft_del_flag(char **str, int nb);
t_lst				*ft_addlist(t_lst *list, t_lst *new_ele);
t_lst				*convert_to_dir(int nb, char **str, t_flag *flag);
long long int		ft_blocks(t_lst *list);
t_size				*ft_format(t_lst *list);
t_flag				*convert_to_flag(char **str);
void				ft_ls(t_flag *flag, t_lst *rep, int ac, int nb_flag);
t_lst				*ft_make_list(DIR *dir, t_flag *flag, char *rep);
void				ft_lstprint(t_lst *list, t_flag *flag, t_size *size_l,
												long long int blocks);
t_lst				*ft_ls_l(char *rep, t_lst *list);
void				ft_ls_r(t_flag *flag, t_lst *list);
void				ft_error(char *s);
t_lst				*ft_newele(char *name);
char				**ft_sort_char(char **str, t_flag *flag);
t_lst				*merge_sort(t_lst *head);
t_lst				*merge_sort_t(t_lst *head);
void				ft_lst_free(t_lst **list);
void				ft_putchar_socket(t_lst *list);
void				ft_putstr_right(t_lst *list);
void				ft_print_flag(t_flag *flag, t_size *size_l, t_lst *list);
t_size				*ft_format_spec(t_flag *flag, t_size *size_l, t_lst *list);
void				ft_print_ln(t_lst *list, int flag);
void				ft_print_color(t_lst *list);
void				ft_print_f(t_lst *list, int flag, int put);
int					ft_aclattr(t_lst *list);
void				ft_print_nodir(t_lst *list);
#endif
