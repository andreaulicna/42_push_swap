/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:45:51 by aulicna           #+#    #+#             */
/*   Updated: 2023/05/01 17:53:57 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	int	tmp_num;

	if (!stack || ps_lstsize_flag(stack) == 1)
		return ;
	while (stack->prev->flag != 1)
	{
		tmp_num = stack->num;
		stack->num = stack->prev->num;
		stack->prev->num = tmp_num;
		stack = stack->prev;
	}
}

void	reverse_rotate_a(t_stack *a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_stack *b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}

void	rrr_checker(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
