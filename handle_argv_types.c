/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_argv_types.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:21:01 by aulicna           #+#    #+#             */
/*   Updated: 2023/04/22 11:44:19 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_argv_str(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

int	count_argv_str(char **tmp_argv)
{
	int	i;

	i = 0;
	while (tmp_argv[i] != 0)
		i++;
	i += 1;
	return (i);
}

t_stack	*handle_argv_str(int argc, char **tmp_argv)
{
	t_stack	*a;

	if (is_number(argc - 1, tmp_argv, 0) == 0
		|| fits_in_integer(argc - 1, tmp_argv, 0) == 0)
	{
		free_argv_str(argc, tmp_argv);
		ps_error();
	}
	a = ps_init_fill_a(argc - 1, tmp_argv, 0);
	return (a);
}

t_stack	*handle_argv_int(int argc, char **argv)
{
	t_stack	*a;

	if (is_number(argc, argv, 1) == 0
		|| fits_in_integer(argc, argv, 1) == 0)
		ps_error();
	a = ps_init_fill_a(argc, argv, 1);
	return (a);
}
