/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:16:56 by aulicna           #+#    #+#             */
/*   Updated: 2023/04/18 19:52:58 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atoi_long(const char *nptr)
{
	unsigned int	i;
	unsigned long	flag;
	long			res;

	i = 0;
	flag = 1;
	res = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-')
	{	
		flag = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (flag * res);
}

int	fits_in_integer(int argc, char **argv, int argv_type)
{
	int		i;
	long	num_to_check;

	i = argv_type;
	while (i < argc)
	{
		num_to_check = ft_atoi_long(argv[i]);
		if (INT_MIN > num_to_check || num_to_check > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

int	is_number(int argc, char **argv, int argv_type)
{
	int	i;
	int	j;

	i = argv_type;
	while (i < argc)
	{
		if ((argv[i][0] == '-' && ft_isdigit(argv[i][1]) != 1))
			return (0);
		else if (ft_isdigit(argv[i][0]) == 0 && argv[i][0] != '-')
			return (0);
		j = 1;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *a)
{
	while (a->next->flag != 1)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}
