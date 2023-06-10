# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aulicna <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 12:41:35 by aulicna           #+#    #+#              #
#    Updated: 2023/04/18 19:54:54 by aulicna          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

MAIN = main.c

SRCS = stacks_init_free.c \
	push_swap_print.c \
	ps_swap.c \
	ps_push.c \
	ps_rotate.c \
	ps_reverse_rotate.c \
	ps_three_nums.c \
	ps_all_nums.c \
	return_final_touch.c \
	find_place.c \
	cal_init_free.c \
	count_ops.c \
	count_ops_calculations.c \
	ready_for_push.c \
	ready_for_push_scenarios.c \
	validators.c \
	validators_2.c \
	error.c \
	handle_argv_types.c \
	lst_utils.c

MAIN_SRCS = $(MAIN) $(SRCS)

OBJS = $(MAIN_SRCS:.c=.o)

NAME_BONUS = checker

SRCS_BONUS = $(SRCS) checker_bonus.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)


LIBFTPRINTF = libftprintf

CFLAGS = -Wall -Werror -Wextra

GCC = gcc

AR = ar rc

all: $(NAME)

${NAME}: $(OBJS)
	make -C $(LIBFTPRINTF)
	$(GCC) $(CFLAGS) $(OBJS) libftprintf/$(LIBFTPRINTF).a -o $(NAME)
	
bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	make -C $(LIBFTPRINTF)
	$(GCC) $(CFLAGS) $(OBJS_BONUS) libftprintf/$(LIBFTPRINTF).a -o $(NAME_BONUS)

.c.o:
	$(GCC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C $(LIBFTPRINTF)
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	make fclean -C $(LIBFTPRINTF)
	@rm -f $(NAME) $(NAME_BONUS)

.PHONY: all clean fclean re
