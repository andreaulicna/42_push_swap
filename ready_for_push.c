/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ready_for_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:11:22 by aulicna           #+#    #+#             */
/*   Updated: 2023/04/08 18:14:33 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Helper function for the ready_for_push function that handles
the else scenario for stack B.*/
static void	rfp_else_b(t_stack *b, t_cal *cal)
{
	if (cal->r_b < cal->rr_b)
	{
		while (cal->r_b > 0)
		{
			rotate_b(b);
			cal->r_b--;
		}
	}
	else
	{
		while (cal->rr_b > 0)
		{
			reverse_rotate_b(b);
			cal->rr_b--;
		}
	}
}

/* Helper function for the ready_for_push function that handles
the else scenario for stack A.*/
static void	rfp_else_a(t_stack *a, t_cal *cal)
{
	if (cal->r_a < cal->rr_a)
	{
		while (cal->r_a > 0)
		{
			rotate_a(a);
			cal->r_a--;
		}
	}
	else
	{
		while (cal->rr_a > 0)
		{
			reverse_rotate_a(a);
			cal->rr_a--;
		}
	}
}

/* Rotates both of the stacks so that the selected number to push
can be pushed. */
void	ready_for_push(t_stack **a, t_stack **b, t_cal *cal)
{
	if (cal->f_rrr == 1)
		rfp_reverse_rotate_ops(*a, *b, cal);
	else if (cal->f_rr == 1)
		rfp_rotate_ops(*a, *b, cal);
	else if (cal->f_ar_brr == 1)
		rfp_ar_brr(*a, *b, cal);
	else if (cal->f_arr_br == 1)
		rfp_arr_br(*a, *b, cal);
	else
	{
		rfp_else_b(*b, cal);
		rfp_else_a(*a, cal);
	}
}
