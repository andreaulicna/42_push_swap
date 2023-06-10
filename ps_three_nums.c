/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_three_nums.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 13:19:42 by aulicna           #+#    #+#             */
/*   Updated: 2023/04/06 15:54:50 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_three_nums(t_stack *a)
{
	if ((a->num > a->next->num) && (a->num < a->prev->num)
		&& a->next->num < a->prev->num)
		swap_a(a);
	else if (a->num > a->prev->num && a->num > a->prev->num
		&& a->next->num < a->prev->num)
		rotate_a(a);
	else if (a->num < a->next->num && a->num > a->prev->num
		&& a->next->num > a->prev->num)
		reverse_rotate_a(a);
	else if (a->num < a->next->num && a->num < a->prev->num
		&& a->next->num > a->prev->num)
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (a->num > a->next->num && a->num > a->prev->num
		&& a->next->num > a->prev->num)
	{
		swap_a(a);
		reverse_rotate_a(a);
	}
}
