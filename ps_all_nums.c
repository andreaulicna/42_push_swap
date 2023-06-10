/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_all_nums.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:16:47 by aulicna           #+#    #+#             */
/*   Updated: 2023/04/08 18:24:42 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Finds the biggest number in a stack */
int	biggest_num(t_stack *stack)
{
	t_stack	*biggest;
	t_stack	*current;

	biggest = stack;
	current = stack->next;
	while (current->flag != 1)
	{
		if (current->num > biggest->num)
			biggest = current;
		current = current->next;
	}
	return (biggest->num);
}

/* Finds the smallest number in a stack */
int	smallest_num(t_stack *stack)
{
	t_stack	*smallest;
	t_stack	*current;

	smallest = stack;
	current = stack->next;
	while (current->flag != 1)
	{
		if (current->num < smallest->num)
			smallest = current;
		current = current->next;
	}
	return (smallest->num);
}

/* Finds the number to push by going through the whole of stack A and
calculating the operations needed for each and every number and then
return the one that requires the smallest number of operations. 
The returned cal structure includes the number to push as well as all
the value for all the calculations. */
t_cal	*ps_find_num_to_push(t_stack **a, t_stack **b)
{
	t_stack	*current;
	int		biggest_b;
	int		smallest_b;
	t_cal	*cal;

	cal = count_ops_first_number(a, b);
	current = (*a)->next;
	biggest_b = biggest_num(*b);
	smallest_b = smallest_num(*b);
	while (current->flag != 1)
	{
		if (smallest_b > current->num || biggest_b < current->num)
			count_ops_smallest_biggest(cal, a, b, current);
		else
			count_ops_middle(cal, a, b, current);
		current = current->next;
	}
	return (cal);
}

/* The main function that handles 3+ numbers. */
void	ps_all_nums(t_stack **a, t_stack **b)
{
	t_cal	*cal;

	if (ps_lstsize_flag(*a) != 4)
		push_b(a, b);
	push_b(a, b);
	while (ps_lstsize_flag(*a) != 3)
	{
		cal = ps_find_num_to_push(a, b);
		ready_for_push(a, b, cal);
		push_b(a, b);
		free_cal(cal);
	}
	ps_three_nums(*a);
	ps_return_all_to_a(a, b);
	ps_a_final_touch(a);
}
