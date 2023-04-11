# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/23 01:02:26 by aaoutem-          #+#    #+#              #
#    Updated: 2023/04/11 01:28:17 by aaoutem-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -rf
FLAGS = -Wall -Wextra -Werror  -g -fsanitize=address
HEADER = push_swap.h
BONUS_HEADER = bonus/checker_bonus.h

SRCS = main.c \
	pars.c \
	error.c \
	utils_fs/ft_atoi.c \
	utils_fs/ft_split.c \
	utils_fs/ft_strlen.c \
	utils_fs/ft_substr.c \
	utils_fs/is_empty.c \
	stack/ft_lstadd_front.c \
	stack/ft_lstnew.c \
	stack/push_elem.c \
	stack/pop_elem.c \
	stack/ft_lstiter.c \
	stack/ft_lstadd_back.c \
	stack/stack_construction.c \
	LIS.c \
	LIS2.c \
	src/p_nd_s.c \
	src/r_rot.c \
	src/rot.c \
	src/ft_putstr.c \
	sort.c \
	free_mem.c \
	sort_action.c \
	three_case.c

BONUS = bonus/checker_bonus.c \
	bonus/error.c \
	bonus/pars_bonus.c \
	bonus/sort_check.c \
	bonus/src/ft_putstr.c \
	bonus/src/p_nd_s.c \
	bonus/src/r_rot.c \
	bonus/src/rot.c \
	bonus/stack/ft_lstadd_back.c \
	bonus/stack/stack_construction.c\
	bonus/stack/ft_lstnew.c \
	bonus/stack/ft_lstlast.c \
	bonus/stack/ft_lstiter.c \
	bonus/stack/pop_elem.c \
	bonus/stack/push_elem.c \
	bonus/stack/ft_lstadd_front.c \
	bonus/util_fcts_bonus/ft_atoi.c \
	bonus/util_fcts_bonus/ft_split.c \
	bonus/util_fcts_bonus/ft_strlen.c\
	bonus/util_fcts_bonus/ft_strncmp.c \
	bonus/util_fcts_bonus/ft_substr.c \
	bonus/util_fcts_bonus/ft_malloc.c \
	bonus/gnl/get_next_line.c \
	bonus/gnl/get_next_line_utils.c 

OBJ_F = ${SRCS:.c=.o}

BONUS_OBJF = ${BONUS:.c=.o}

all : ${NAME}

${NAME} : ${OBJ_F}
	${CC} ${FLAGS} ${OBJ_F} -o push_swap

bonus : ${BONUS_OBJF} ${BONUS_HEADER} ${NAME}
	${CC} ${FLAGS} ${BONUS_OBJF} -o checker

%.o : %.c ${HEADER}
	${CC} ${FLAGS} $< -c -o $@

clean :
	${RM} ${OBJ_F} ${BONUS_OBJF}

fclean : clean
	${RM} ${NAME} 

re : fclean all

# . PHONY re clean fclean bonus
# bonus/util_fcts_bonus/ft_strjoin.c \
	bonus/util_fcts_bonus/ft_lstiter.c\
