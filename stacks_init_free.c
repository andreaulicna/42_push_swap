/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_init_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:34:27 by aulicna           #+#    #+#             */
/*   Updated: 2023/05/01 17:38:44 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_lstnew(int num)
{
	t_stack	*tmp;

	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return (NULL);
	tmp->flag = 0;
	tmp->num = num;
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

t_stack	*ps_init_fill_a(int argc, char **argv, int arg_type)
{
	int		i;
	t_stack	*stack;

	i = arg_type + 1;
	stack = ps_lstnew(ft_atoi(argv[arg_type]));
	while (i < argc)
	{
		ps_lstadd_back(&stack, ps_lstnew(ft_atoi(argv[i])));
		i++;
	}
	ps_lstlast(stack)->next = stack;
	stack->flag = 1;
	while (stack->next->prev == NULL)
	{
		stack->next->prev = stack;
		stack = stack->next;
	}
	return (stack);
}

t_stack	*ps_init_fill_b(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->flag = 1;
	stack->num = 0;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

static void	free_stack(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*current;

	current = stack->next;
	while (current != stack)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	free(stack);
	stack = NULL;
}

void	free_stacks(t_stack *a, t_stack *b)
{
	free_stack(a);
	free(b);
}
