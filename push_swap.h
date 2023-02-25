/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:57:15 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/24 22:56:40 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

typedef struct s_stack
{
	int x;
	int	size;
	struct s_stack  *next;
}	t_stack;


int	*parsing_f(int ac, char **av, int *l);
/*---------stack functions--------*/
t_stack    **ft_lstadd_front(t_stack **stack, t_stack *node);
void    ft_lstadd_back(t_stack  **stack, t_stack *node);
t_stack	*ft_lstnew(int data);
void	stack_init(int *k, t_stack **A, t_stack **B, int *l);
int		pop_el(t_stack **stack);
void   	push_el(t_stack **stack, int data);
/*---------utils functions--------*/
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char *s, char c, int *n);
size_t	ft_strlen(char *s);
int		ft_atoi(char *str);
void	ft_putstr_fd(char *s, int fd);
void	errors(char *str);
/*-----------operations----------*/
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	sa(t_stack  **a);
void	sb(t_stack **b);
void	ss(t_stack	**a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

#endif