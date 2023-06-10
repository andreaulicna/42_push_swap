/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:34:55 by aulicna           #+#    #+#             */
/*   Updated: 2023/05/01 18:05:19 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libftprintf/ft_printf.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				flag;
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_cal
{
	int	r_a;
	int	r_b;
	int	rr;
	int	rr_a;
	int	rr_b;
	int	rrr;
	int	rr_ops;
	int	rrr_ops;
	int	arr_br;
	int	ar_brr;
	int	total_ops;
	int	num_push;
	int	f_arr_br;
	int	f_ar_brr;
	int	f_rr;
	int	f_rrr;

}	t_cal;

// Functions handling argv passed as int and str (handle_argv_types.c)
void	free_argv_str(int argc, char **argv);
int		count_argv_str(char **tmp_argv);
t_stack	*handle_argv_str(int argc, char **tmp_argv);
t_stack	*handle_argv_int(int argc, char **argv);

// Stack init and free functions (stacks_init_free.c)
t_stack	*ps_lstnew(int num);
t_stack	*ps_init_fill_a(int argc, char **argv, int arg_type);
t_stack	*ps_init_fill_b(void);
void	free_stacks(t_stack *a, t_stack *b);

// Cal init and free functions (cal_init_free.c)
t_cal	*ps_init_call(void);
void	free_cal(t_cal *cal);

// Functions validating input arguments (validators.c, validators_2.c)
int		is_number(int argc, char **argv, int argv_type);
int		fits_in_integer(int argc, char **argv, int argv_type);
int		check_for_duplicate_nodes(t_stack *a);
int		is_sorted(t_stack *a);
void	ready_for_push_swap(t_stack *a, t_stack *b);

// Algorithm for 3 nums (ps_all_nums.c)
void	ps_three_nums(t_stack *a);
// Algorithm for all nums (ps_three_nums.c)
void	ps_all_nums(t_stack **a, t_stack **b);
int		biggest_num(t_stack *stack);
int		smallest_num(t_stack *stack);

// Functions calculating the number of operations need to push a number 
// from stack A into a correct position in stack B. (count_ops.c)
t_cal	*count_ops_first_number(t_stack **a, t_stack **b);
void	count_ops_smallest_biggest(t_cal *cal, t_stack **a, t_stack **b,
			t_stack *current);
void	count_ops_middle(t_cal *cal, t_stack **a, t_stack **b,
			t_stack *current);

// Underlying calculation for the count ops functions (count_ops_calculations.c)
int		count_rotate_top(t_stack **stack, int num);
int		count_reverse_rotate_top(t_stack *stack, int num);
int		count_common_rotations(int a_rot, int b_rot);
int		choose_total_ops(t_cal *cal, int min);
void	count_choose_best_rotations(t_cal *cal);

// Find the correct place to put a number in (find_place.c)
int		find_place_in_a(t_stack **a, int num_b);
int		find_place_in_b(t_stack **b, int num_a);

// Functions preparing both stacks for the push operation. 
// (ready_for_push.c & ready_for_push_scenarios.c)
void	ready_for_push(t_stack **a, t_stack **b, t_cal *cal);
void	rfp_reverse_rotate_ops(t_stack *a, t_stack *b, t_cal *cal);
void	rfp_rotate_ops(t_stack *a, t_stack *b, t_cal *cal);
void	rfp_ar_brr(t_stack *a, t_stack *b, t_cal *cal);
void	rfp_arr_br(t_stack *a, t_stack *b, t_cal *cal);

// Rules
// 	Swap
void	swap_a(t_stack *a);
void	swap_b(t_stack *b);
void	swap_swap(t_stack *a, t_stack *b);
void	swap_stack(t_stack *stack);

//	Rotate
void	rotate_a(t_stack *a);
void	rotate_b(t_stack *b);
void	rotate_rotate(t_stack *a, t_stack *b);
void	rotate_stack(t_stack *stack);

//	Reverse rotate
void	reverse_rotate_a(t_stack *a);
void	reverse_rotate_b(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *stack);

//	Push
void	push(t_stack **src, t_stack **dst);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);

// 	Functions needed for checker that are in the rules files
void	rotate_rotate_checker(t_stack *a, t_stack *b);
void	rrr_checker(t_stack *a, t_stack *b);
void	swap_swap_checker(t_stack *a, t_stack *b);

// Return to a and final touch functions (return_final_touch.c)
void	ps_return_all_to_a(t_stack **a, t_stack **b);
void	ps_a_final_touch(t_stack **a);

// Printing functions (push_swap_print.c)
// Note: not used in the code, but can be added anywhere
void	ps_print_stacks(t_stack *a, t_stack *b);
void	ps_print_stacks_rev(t_stack *a, t_stack *b);

// List utils
int		ps_lstsize(t_stack *lst);
int		ps_lstsize_flag(t_stack *lst);
t_stack	*ps_lstlast(t_stack *lst);
void	ps_lstadd_back(t_stack **lst, t_stack *new);
void	ps_lstadd_front(t_stack **lst, t_stack *new);

// Other utils (error.c)
void	ps_error(void);

#endif
