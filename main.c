/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:00:05 by aulicna           #+#    #+#             */
/*   Updated: 2023/04/18 19:53:23 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (argc == 3 && (a->num > a->next->num))
		rotate_a(a);
	else if (argc == 4)
		ps_three_nums(a);
	else if (argc > 4 && is_sorted(a) == 0)
		ps_all_nums(&a, &b);
	free_stacks(a, b);
	return (0);
}
