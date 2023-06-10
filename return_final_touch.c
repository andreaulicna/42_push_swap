/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_final_touch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:46:04 by aulicna           #+#    #+#             */
/*   Updated: 2023/04/08 17:49:21 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Helper function for the ps_return_all_to_a functions.
Handles the return of a number that will be the new smallest/ biggest
number in stack A. */
static void	return_smallest_biggest(t_stack **a, t_stack **b, int smallest_a)
{
	if (count_rotate_top(a, smallest_a)
		< count_reverse_rotate_top(*a, smallest_a))
	{
		while ((*a)->num != smallest_a)
			rotate_a(*a);
	}
	else
	{
		while ((*a)->num != smallest_a)
			reverse_rotate_a(*a);
	}
	push_a(a, b);
}

/* Helper function for the ps_return_all_to_a functions.
Handles the return of a middle number. */
static void	return_middle(t_stack **a, t_stack **b)
{
	int	num_a;

	num_a = find_place_in_a(a, (*b)->num);
	if (num_a == (*a)->num)
	{
		push_a(a, b);
	}
	else
	{
		if (count_rotate_top(a, num_a) < count_reverse_rotate_top(*a, num_a))
		{
			while ((*a)->num != num_a)
				rotate_a(*a);
		}
		else
		{
			while ((*a)->num != num_a)
				reverse_rotate_a(*a);
		}
		push_a(a, b);
	}
}

/* Returns all the number that were sent to stack B back to stack A */
void	ps_return_all_to_a(t_stack **a, t_stack **b)
{
	int	size_b;
	int	smallest_a;
	int	biggest_a;

	size_b = ps_lstsize_flag(*b);
	while (size_b > 0)
	{
		smallest_a = smallest_num(*a);
		biggest_a = biggest_num(*a);
		if ((*b)->num > biggest_a || (*b)->num < smallest_a)
			return_smallest_biggest(a, b, smallest_a);
		else
			return_middle(a, b);
		size_b--;
	}
}

/* Ensures that stack A is correctly rotated at the end of the program. */
void	ps_a_final_touch(t_stack **a)
{
	int	smallest_a;

	smallest_a = smallest_num(*a);
	if (count_rotate_top(a, smallest_a)
		< count_reverse_rotate_top(*a, smallest_a))
	{
		while ((*a)->num != smallest_a)
			rotate_a(*a);
	}
	else
	{
		while ((*a)->num != smallest_a)
			reverse_rotate_a(*a);
	}
}
