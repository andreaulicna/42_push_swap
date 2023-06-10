/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_init_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aulicna <aulicna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:58:41 by aulicna           #+#    #+#             */
/*   Updated: 2023/05/01 17:28:18 by aulicna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cal	*ps_init_call(void)
{
	t_cal	*cal;

	cal = (t_cal *) malloc(sizeof(t_cal));
	cal->r_a = -1;
	cal->r_b = -1;
	cal->rr = -1;
	cal->rr_a = -1;
	cal->rr_b = -1;
	cal->rrr = -1;
	cal->rr_ops = -1;
	cal->rrr_ops = -1;
	cal->arr_br = -1;
	cal->ar_brr = -1;
	cal->total_ops = 0;
	cal->num_push = -1;
	cal->f_arr_br = 0;
	cal->f_ar_brr = 0;
	cal->f_rr = 0;
	cal->f_rrr = 0;
	return (cal);
}

void	free_cal(t_cal *cal)
{
	free(cal);
	cal = NULL;
}
