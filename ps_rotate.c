/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:35:41 by aulicna           #+#    #+#             */
/*   Updated: 2023/05/01 17:53:43 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_stack *stack)
{
	int	tmp_num;

	if (!stack || ps_lstsize_flag(stack) == 1)
		return ;
	while (stack->next->flag != 1)
	{
		tmp_num = stack->num;
		stack->num = stack->prev->num;
		stack->prev->num = tmp_num;
		stack = stack->next;
	}
}

void	rotate_a(t_stack *a)
{
	rotate_stack(a);
	write(1, "ra\n", 3);
}

void	rotate_b(t_stack *b)
{
	rotate_stack(b);
	write(1, "rb\n", 3);
}

void	rotate_rotate(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
	write(1, "rr\n", 3);
}

void	rotate_rotate_checker(t_stack *a, t_stack *b)
{
	rotate_stack(a);
	rotate_stack(b);
}
