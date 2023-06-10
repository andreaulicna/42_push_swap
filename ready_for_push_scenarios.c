/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_for_push_scenarios.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:16:31 by aulicna           #+#    #+#             */
/*   Updated: 2023/04/08 18:17:04 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Helper function for the ready_for_push function that handles
the rrr scenario.*/
void	rfp_reverse_rotate_ops(t_stack *a, t_stack *b, t_cal *cal)
{
	while (cal->rrr > 0)
	{
		rrr(a, b);
		cal->rrr--;
		cal->rr_a--;
		cal->rr_b--;
	}
	while (cal->rr_a > 0)
	{
		reverse_rotate_a(a);
		cal->rr_a--;
	}
	while (cal->rr_b > 0)
	{
		reverse_rotate_b(b);
		cal->rr_b--;
	}
}

/* Helper function for the ready_for_push function that handles
the rr scenario.*/
void	rfp_rotate_ops(t_stack *a, t_stack *b, t_cal *cal)
{
	while (cal->rr > 0)
	{
		rotate_rotate(a, b);
		cal->rr--;
		cal->r_a--;
		cal->r_b--;
	}
	while (cal->r_a > 0)
	{
		rotate_a(a);
		cal->r_a--;
	}
	while (cal->r_b > 0)
	{
		rotate_b(b);
		cal->r_b--;
	}
}

/* Helper function for the ready_for_push function that handles
the ar_brr scenario.*/
void	rfp_ar_brr(t_stack *a, t_stack *b, t_cal *cal)
{
	while (cal->r_a > 0)
	{
		rotate_a(a);
		cal->r_a--;
	}
	while (cal->rr_b > 0)
	{
		reverse_rotate_b(b);
		cal->rr_b--;
	}
}

/* Helper function for the ready_for_push function that handles
the arr_br scenario.*/
void	rfp_arr_br(t_stack *a, t_stack *b, t_cal *cal)
{
	while (cal->rr_a > 0)
	{
		reverse_rotate_a(a);
		cal->rr_a--;
	}
	while (cal->r_b > 0)
	{
		rotate_b(b);
		cal->r_b--;
	}
}
