/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:40:53 by aulicna           #+#    #+#             */
/*   Updated: 2023/05/01 18:05:39 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	inst_strlen(char *inst)
{
	int	i;

	i = 0;
	while (inst[i] != '\n' && inst[i] != '\0')
		i++;
	return (i);
}

static void	perform_instructions(t_stack **a, t_stack **b,
		char *inst, int inst_len)
{
	if (!ft_strncmp(inst, "sa", inst_len))
		swap_stack(*a);
	else if (!ft_strncmp(inst, "sb", inst_len))
		swap_stack(*b);
	else if (!ft_strncmp(inst, "ss", inst_len))
		swap_swap_checker(*a, *b);
	else if (!ft_strncmp(inst, "pa", inst_len))
		push(b, a);
	else if (!ft_strncmp(inst, "pb", inst_len))
		push(a, b);
	else if (!ft_strncmp(inst, "ra", inst_len))
		rotate_stack(*a);
	else if (!ft_strncmp(inst, "rb", inst_len))
		rotate_stack(*b);
	else if (!ft_strncmp(inst, "rr", inst_len))
		rotate_rotate_checker(*a, *b);
	else if (!ft_strncmp(inst, "rra", inst_len))
		reverse_rotate(*a);
	else if (!ft_strncmp(inst, "rrb", inst_len))
		reverse_rotate(*b);
	else if (!ft_strncmp(inst, "rrr", inst_len))
		rrr_checker(*a, *b);
	else
		ps_error();
}

static void	read_then_perform_instructions(t_stack **a, t_stack **b)
{
	static char	*inst;

	inst = get_next_line(0);
	while (inst)
	{
		perform_instructions(a, b, inst, inst_strlen(inst));
		free(inst);
		inst = get_next_line(0);
	}
	free(inst);
	if ((*b)->next == NULL && (*b)->prev == NULL && (*b)->num == 0
		&& is_sorted(*a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**tmp_argv;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	else if (argc == 2)
	{
		tmp_argv = ft_split(argv[1], ' ');
		argc = count_argv_str(tmp_argv);
		a = handle_argv_str(argc, tmp_argv);
		free_argv_str(argc, tmp_argv);
	}
	else
		a = handle_argv_int(argc, argv);
	b = ps_init_fill_b();
	ready_for_push_swap(a, b);
	read_then_perform_instructions(&a, &b);
	free_stacks(a, b);
	return (0);
}
