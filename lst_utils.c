/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 16:16:18 by aulicna           #+#    #+#             */
/*   Updated: 2023/04/06 16:17:15 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ps_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	ps_lstsize_flag(t_stack *lst)
{
	int	i;

	i = 0;
	if (lst)
	{
		if (lst->next == NULL)
			return (1);
		lst = lst->next;
	}
	while (lst->flag != 1)
	{
		lst = lst->next;
		i++;
	}
	return (i + 1);
}

t_stack	*ps_lstlast(t_stack *lst)
{
	int	size;

	size = ps_lstsize(lst);
	while (size > 1)
	{
		lst = lst->next;
		size--;
	}
	return (lst);
}

void	ps_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	last = ps_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
}

void	ps_lstadd_front(t_stack **lst, t_stack *new)
{
	if (!new)
	{
		return ;
	}
	if (!lst)
	{
		*lst = new;
		return ;
	}
	else
	{
		new->next = *lst;
		new->prev = (*lst)->prev;
		new->flag = 1;
		(*lst)->prev->next = new;
		(*lst)->prev = new;
		(*lst)->flag = 0;
		*lst = new;
	}
}
