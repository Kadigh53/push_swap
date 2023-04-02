/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 22:23:52 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/02 20:02:13 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

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
}	t_vars;

int		*pars_check(int ac, char **av, int *l);
void	sort_check(t_stack **a, t_stack **b);
char	*get_next_line(int fd);
/*---------stack functions--------*/
// t_stack	*ft_lstnew(int data);m
t_stack	**ft_lstadd_front(t_stack **stack, t_stack *node);
t_stack	*ft_lstnew(int data, int min, int max);
void	ft_lstadd_back(t_stack	**stack, t_stack *node);
void	stack_init(int *k, t_stack **A, t_stack **B, int *l);
void	push_el(t_stack **stack, int data, int min, int max);
int		pop_el(t_stack **stack, t_stack **a);
/*---------utils functions--------*/
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	**ft_split(char *s, char c, int *n);
char	*ft_strjoin(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(char *s);
int		ft_atoi(char *str);
void	errors(char *str);
/*-----------operations----------*/
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	sa(t_stack	**a);
void	sb(t_stack **b);
void	ss(t_stack	**a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif