/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:52:27 by aulicna           #+#    #+#             */
/*   Updated: 2023/04/22 11:44:32 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_for_duplicate_nodes(t_stack *a)
{
	t_stack	*to_check;

	while (a->next->flag != 1)
	{
		to_check = a->next;
		while (to_check->flag != 1)
		{
			if (a->num == to_check->num)
				return (0);
			to_check = to_check->next;
		}
		a = a->next;
	}
	return (1);
}

void	ready_for_push_swap(t_stack *a, t_stack *b)
{
	if (check_for_duplicate_nodes(a) == 0)
	{
		free_stacks(a, b);
		ps_error();
	}
}
