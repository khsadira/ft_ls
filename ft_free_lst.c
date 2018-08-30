#include "ft_ls.h"

void	ft_lst_free(t_lst **list)
{
	t_lst	*tmp;

	while (*list)
	{
		tmp = *list;
		if (tmp->name)
			ft_strdel(&tmp->name);
		if (tmp->path)
			ft_strdel(&tmp->path);
	/*	if (tmp->right)
			ft_strdel(&tmp->right);
		if (tmp->uid)
			ft_strdel(&tmp->uid);
		if (tmp->guid)
			ft_strdel(&tmp->guid);
		if (tmp->day)
			ft_strdel(&tmp->day);
		if (tmp->hm)
			ft_strdel(&tmp->hm);
		if (tmp->month)
			ft_strdel(&tmp->month);
		if (tmp->n_link)
			ft_strdel(&tmp->n_link);*/
		*list = (*list)->next;
		free(tmp);
	}
}
