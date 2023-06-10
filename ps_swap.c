/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 14:28:49 by aulicna           #+#    #+#             */
/*   Updated: 2023/05/01 17:53:16 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack *stack)
{
	int	tmp_num;

	if (!stack || ps_lstsize_flag(stack) == 1)
		return ;
	tmp_num = stack->num;
	stack->num = stack->next->num;
	stack->next->num = tmp_num;
}

void	swap_a(t_stack *a)
{
	swap_stack(a);
	ft_printf("sa\n");
}

void	swap_b(t_stack *b)
{
	swap_stack(b);
	write(1, "sb\n", 3);
}

void	swap_swap(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
	write(1, "ss\n", 3);
}

void	swap_swap_checker(t_stack *a, t_stack *b)
{
	swap_stack(a);
	swap_stack(b);
}
