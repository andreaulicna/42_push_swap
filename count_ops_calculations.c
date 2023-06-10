/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counts_ops_calculations.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:01:57 by aulicna           #+#    #+#             */
/*   Updated: 2023/04/08 18:02:43 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Counts the normal rotations needed to get a specific number to the top 
of the stack. */
int	count_rotate_top(t_stack **stack, int num)
{
	int		i;
	t_stack	*current;

	current = *stack;
	i = 0;
	while (current->num != num)
	{
		current = current->next;
		i++;
	}
	return (i);
}

/* Counts the reverse rotations needed to get a specific number to the top 
of the stack. */
int	count_reverse_rotate_top(t_stack *stack, int num)
{
	int		i;
	t_stack	*current;

	current = stack;
	i = 0;
	while (current->num != num)
	{
		current = current->prev;
		i++;
	}
	return (i);
}

/* Counts rotations that can be performed at once. 
Note: This is a general function that can be used for both normal rotations 
and reverse rotations as needed.*/
int	count_common_rotations(int a_rot, int b_rot)
{
	if (a_rot > 0 && b_rot > 0)
	{
		if (a_rot == b_rot)
			return (a_rot);
		else if (a_rot < b_rot)
			return (a_rot);
		else if (a_rot > b_rot)
			return (b_rot);
	}
	return (0);
}

/* Chooses the final (smallest) number of operations needed to
push a number from stack A to a correct position in stack B. */
int	choose_total_ops(t_cal *cal, int min)
{
	cal->f_arr_br = 1;
	if (cal->ar_brr < min)
	{
		min = cal->ar_brr;
		cal->f_arr_br = 0;
		cal->f_ar_brr = 1;
	}
	if (cal->rr_ops < min)
	{
		min = cal->rr_ops;
		cal->f_arr_br = 0;
		cal->f_ar_brr = 0;
		cal->f_rr = 1;
	}
	if (cal->rrr_ops < min)
	{
		min = cal->rrr_ops;
		cal->f_arr_br = 0;
		cal->f_ar_brr = 0;
		cal->f_rr = 0;
		cal->f_rrr = 1;
	}
	return (min);
}

void	count_choose_best_rotations(t_cal *cal)
{
	if (cal->rr > 0 || cal->rrr > 0)
	{
		if (cal->r_a > cal->r_b)
			cal->rr_ops = cal->rr + (cal->r_a - cal->rr);
		else
			cal->rr_ops = cal->rr + (cal->r_b - cal->rr);
		if (cal->rr_a > cal->rr_b)
			cal->rrr_ops = cal->rrr + (cal->rr_a - cal->rrr);
		else
			cal->rrr_ops = cal->rrr + (cal->rr_b - cal->rrr);
		cal->total_ops = choose_total_ops(cal, cal->arr_br);
	}
	else
	{
		if (cal->r_b > cal->rr_b)
			cal->total_ops = cal->rr_b;
		else
			cal->total_ops = cal->r_b;
		if (cal->r_a > cal->rr_a)
			cal->total_ops += cal->rr_a;
		else
			cal->total_ops += cal->r_a;
	}
}
