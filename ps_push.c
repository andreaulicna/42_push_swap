/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:43:51 by aulicna           #+#    #+#             */
/*   Updated: 2023/05/01 17:46:36 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	pop(t_stack **stack)
{
	int		pop_num;
	t_stack	*del_lst;

	if (ps_lstsize_flag(*stack) == 1)
	{
		pop_num = (*stack)->num;
		(*stack)->next = NULL;
		(*stack)->prev = NULL;
		(*stack)->num = 0;
		(*stack)->flag = 0;
		return (pop_num);
	}
	del_lst = (*stack);
	pop_num = (*stack)->num;
	(*stack)->prev->next = (*stack)->next;
	(*stack)->next->prev = (*stack)->prev;
	(*stack) = (*stack)->next;
	(*stack)->flag = 1;
	free(del_lst);
	return (pop_num);
}

void	push(t_stack **src, t_stack **dst)
{
	int		tmp_num;
	t_stack	*stack;

	tmp_num = pop(src);
	if ((*dst)->next == NULL)
	{
		(*dst)->next = (*dst);
		(*dst)->prev = (*dst);
		(*dst)->flag = 1;
		(*dst)->num = tmp_num;
	}
	else
	{
		stack = ps_lstnew(tmp_num);
		ps_lstadd_front(dst, stack);
	}
}

void	push_a(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}

void	push_b(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
