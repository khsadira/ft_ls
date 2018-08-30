/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sort_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khsadira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:54:53 by khsadira          #+#    #+#             */
/*   Updated: 2018/06/22 14:28:53 by khsadira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_lst	*mergesplit(t_lst *head)
{
	t_lst	*fast;
	t_lst	*slow;
	t_lst	*tmp;

	fast = head;
	slow = head;
	while (fast->next && fast->next->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	tmp = slow->next;
	slow->next = NULL;
	return (tmp);
}

static t_lst  *merge(t_lst *first, t_lst *second)
{
	if (!first)
		return second;

	if (!second)
		return first;

	if (first->buf.st_mtime > second->buf.st_mtime)
	{
		first->next = merge(first->next, second);
		first->next->bfr = first;
		first->bfr = NULL;
		return (first);
	}
	else if (first->buf.st_mtime == second->buf.st_mtime)
	{
		if (ft_strcmp(first->name, second->name) <= 0)
		{
			first->next = merge(first->next, second);
			first->next->bfr = first;
			first->bfr = NULL;
			return (first);
		}
		else
		{
			second->next = merge(first, second->next);
			second->next->bfr = second;
			second->bfr = NULL;
			return (second);
		}
	}
	else
	{
		second->next = merge(first, second->next);
		second->next->bfr = second;
		second->bfr = NULL;
		return (second);
	}
}

t_lst	*merge_sort_t(t_lst *head)
{
	if (!head || !head->next)
		return head;
	t_lst *second = mergesplit(head);

	head = merge_sort_t(head);
	second = merge_sort_t(second);
	return (merge(head, second));
}
