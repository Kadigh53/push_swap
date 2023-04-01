/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:35:40 by kadigh            #+#    #+#             */
/*   Updated: 2023/04/01 19:08:01 by kadigh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS 
# define CHECKER_BONUS 

#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int x;
	int min;
	int max;
	int	size;
	struct s_stack  *next;
}  t_stack;

typedef struct s_vars
{
    t_stack *a;
    t_stack *b; 
} t_vars;

int	    *pars_check(int ac, char **av);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char *s, char c, int *n);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(char *s);
int		ft_atoi(char *str);
void	errors(char *str);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	sa(t_stack  **a, int mode);
void	sb(t_stack **b, int mode);
void	ss(t_stack	**a, t_stack **b);
void	ra(t_stack **a, int mode);
void	rb(t_stack **b, int mode);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a, int mode);
void	rrb(t_stack **b, int mode);
void	rrr(t_stack **a, t_stack **b);

# endif