/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_place.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:53:13 by aulicna           #+#    #+#             */
/*   Updated: 2023/04/08 17:55:45 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Helper function for the find_place_in_b function. */
static int	find_place_in_b_check(t_stack **b, int num_a, int num_in_b)
{
	if ((*b)->num < num_a && num_in_b < (*b)->num)
		return ((*b)->num);
	else
		return (num_in_b);
}

int	find_place_in_b(t_stack **b, int num_a)
{
	int		num_in_b;
	int		smallest_b;
	t_stack	*current;

	smallest_b = smallest_num(*b);
	num_in_b = num_a - 1;
	while (smallest_b < num_in_b)
	{
		current = (*b)->next;
		while (current->flag != 1)
		{
			if (current->num == num_in_b)
				return (find_place_in_b_check(b, num_a, num_in_b));
			current = current->next;
		}
		num_in_b -= 1;
	}
	return (find_place_in_b_check(b, num_a, num_in_b));
}

/* Helper function for the find_place_in_a function. */
static int	find_place_in_a_check(t_stack **a, int num_b, int num_in_a)
{
	if ((*a)->num > num_b && num_in_a > (*a)->num)
		return ((*a)->num);
	else
		return (num_in_a);
}

int	find_place_in_a(t_stack **a, int num_b)
{
	int		num_in_a;
	int		biggest_a;
	t_stack	*current;

	biggest_a = biggest_num(*a);
	num_in_a = num_b + 1;
	while (biggest_a >= num_in_a)
	{
		current = (*a)->next;
		while (current->flag != 1)
		{
			if (current->num == num_in_a)
				return (find_place_in_a_check(a, num_b, num_in_a));
			current = current->next;
		}
		num_in_a += 1;
	}
	return (find_place_in_a_check(a, num_b, num_in_a));
}
