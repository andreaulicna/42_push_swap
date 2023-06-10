/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:26:18 by aulicna           #+#    #+#             */
/*   Updated: 2023/05/01 17:39:52 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ps_print_all_nodes(t_stack *a)
{
	int		i;
	t_stack	*current;

	if (a->next == NULL)
	{
		ft_printf("EMPTY\n");
		return ;
	}
	current = a;
	ft_printf("Node n. 1: %d, ", current->num);
	ft_printf("start flag: %d \n", current->flag);
	i = 2;
	current = current->next;
	while (current->flag != 1)
	{
		ft_printf("Node n. %d: %d, ", i, current->num);
		ft_printf("start flag: %d \n", current->flag);
		i++;
		current = current->next;
	}
}

static void	ps_print_all_nodes_rev(t_stack *a)
{
	int		i;
	t_stack	*current;

	current = a;
	ft_printf("Node n. 1: %d, ", current->num);
	ft_printf("start flag: %d \n", current->flag);
	i = 2;
	current = current->prev;
	while (current->flag != 1)
	{
		ft_printf("Node n. %d: %d, ", i, current->num);
		ft_printf("start flag: %d \n", current->flag);
		i++;
		current = current->prev;
	}
}

void	ps_print_stacks(t_stack *a, t_stack *b)
{
	ft_printf("___STACK A___\n");
	ft_printf("List size: %d\n", ps_lstsize_flag(a));
	ft_printf("***Normal print***\n");
	ps_print_all_nodes(a);
	ft_printf("___STACK B___\n");
	ft_printf("List size: %d\n", ps_lstsize_flag(b));
	ft_printf("***Normal print***\n");
	ps_print_all_nodes(b);
}

void	ps_print_stacks_rev(t_stack *a, t_stack *b)
{
	ft_printf("___STACK A___\n");
	ft_printf("List size: %d\n", ps_lstsize_flag(a));
	ft_printf("***Normal print***\n");
	ps_print_all_nodes_rev(a);
	ft_printf("___STACK B___\n");
	ft_printf("List size: %d\n", ps_lstsize_flag(b));
	ft_printf("***Normal print***\n");
	ps_print_all_nodes(b);
}
