/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:06:36 by aulicna           #+#    #+#             */
/*   Updated: 2023/04/08 18:08:30 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* A general function that counts operations need to get a number from stack A
to the correct position in stack B. It does so regardless of whether the number
to push will be the new smallest/ biggest or middle number in stack B. This is
thanks to sending different number as the num_b parameter to the function.
Note: the "cal->total_ops += 1;" is needed to account for the push operation
that always needs to be performed. */
static t_cal	*count_ops(t_stack **a, t_stack **b, int num_a, int num_b)
{
	t_cal	*cal;

	cal = ps_init_call();
	cal->r_b = count_rotate_top(b, num_b);
	cal->rr_b = count_reverse_rotate_top(*b, num_b);
	cal->r_a = count_rotate_top(a, num_a);
	cal->rr_a = count_reverse_rotate_top(*a, num_a);
	cal->rr = count_common_rotations(cal->r_a, cal->r_b);
	cal->rrr = count_common_rotations(cal->rr_a, cal->rr_b);
	cal->arr_br = cal->rr_a + cal->r_b;
	cal->ar_brr = cal->r_a + cal->rr_b;
	count_choose_best_rotations(cal);
	cal->total_ops += 1;
	return (cal);
}

/* Helper function for the find_num_to_push function. Calculates the
operations needed for the first number in stack A. */
t_cal	*count_ops_first_number(t_stack **a, t_stack **b)
{
	int		biggest_b;
	int		smallest_b;
	t_cal	*cal;

	biggest_b = biggest_num(*b);
	smallest_b = smallest_num(*b);
	if (smallest_b > (*a)->num || biggest_b < (*a)->num)
	{
		cal = count_ops(a, b, (*a)->num, biggest_b);
		cal->num_push = (*a)->num;
	}
	else
	{
		cal = count_ops(a, b, (*a)->num, find_place_in_b(b, (*a)->num));
		cal->num_push = (*a)->num;
	}
	return (cal);
}

/* Helper function for the find_num_to_push function. Calculates the
operations needed if the number from stack A would be the new smallest/
biggest number in stack B if pushed. */
void	count_ops_smallest_biggest(t_cal *cal, t_stack **a, t_stack **b,
		t_stack *current)
{
	t_cal	*tmp_cal;

	tmp_cal = count_ops(a, b, current->num, biggest_num(*b));
	if (tmp_cal->total_ops < cal->total_ops)
	{
		free_cal(cal);
		cal = count_ops(a, b, current->num, biggest_num(*b));
		cal->num_push = current->num;
	}
	free_cal(tmp_cal);
}

/* Helper function for the find_num_to_push function. Calculates the
operations needed if the number from stack A would be a middlet number
in stack B if pushed. */
void	count_ops_middle(t_cal *cal, t_stack **a, t_stack **b, t_stack *current)
{
	t_cal	*tmp_cal;

	tmp_cal = count_ops(a, b, current->num, find_place_in_b(b, current->num));
	if (tmp_cal->total_ops < cal->total_ops)
	{
		free_cal(cal);
		cal = count_ops(a, b, current->num, find_place_in_b(b, current->num));
		cal->num_push = current->num;
	}
	free_cal(tmp_cal);
}
