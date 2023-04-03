/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:57:15 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/03 19:43:39 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>
# include <limits.h>

typedef struct s_stack
{
	int				x;
	int				min;
	int				max;
	int				size;
	struct s_stack	*next;
}	t_stack;

typedef struct s_vars
{
	t_stack	*a;
	t_stack	*b;
	int		*k;
	int		*o_k;
	int		*length;
	int		*le;
	int		*p;
	int		l_max;
}	t_vars;

int		*parsing_f(int ac, char **av, int *l);
void	three_sort(t_stack **a);
void	sort(t_stack **a, t_stack **b);
void	f(t_stack **a, t_stack **b);
int		ft_abs(int a);
int		ft_min(int a, int b);
void	*ft_malloc(int size);
void	nqi_liya(t_stack **a, t_stack **b, t_vars *variables, int *l_max);
void	a_to_b(t_stack **a, t_stack **b, int t, int i);
int		is_itther(t_vars *variables, int x, int *lmax);
int		is_between(int *stack, int start, int next, int x);
// void	rotate(int r_nbr, int e_pos, t_stack **stack);
void	b_to_a(int e_pos[2], t_stack **a, t_stack **b);
void	sort_action(int e_pos[][2], t_stack **a, t_stack **b);

/*---------stack functions--------*/
// t_stack	*ft_lstnew(int data);
t_stack	**ft_lstadd_front(t_stack **stack, t_stack *node);
t_stack	*ft_lstnew(int data, int min, int max);
void	ft_lstadd_back(t_stack **stack, t_stack *node);
void	stack_init(int *k, t_stack **A, t_stack **B, int *l);
void	push_el(t_stack **stack, int data, int min, int max);
int		pop_el(t_stack **stack, t_stack **a);
/*---------utils functions--------*/
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char *s, char c, int *n);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(char *s);
int		ft_atoi(char *str);
void	errors(char *str);
/*-----------operations----------*/

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	sa(t_stack **a, int mode);
void	sb(t_stack **b, int mode);
void	ss(t_stack	**a, t_stack **b);
void	ra(t_stack **a, int mode);
void	rb(t_stack **b, int mode);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, int mode);
void	rrb(t_stack **b, int mode);
void	rrr(t_stack **a, t_stack **b);

#endif