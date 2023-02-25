/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:14:17 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/24 22:56:36 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


// typedef struct s_stack
// {
// 	int x;
// 	int	size;
// 	struct s_stack  *next;
// }	t_stack;





void	pa(t_stack **a, t_stack **b)
{
	int data;
	data = pop_el(b);
	if (data == 0 && !((*b)->next))
		return ;
	push_el(a, data);
	// ft_putstr_fd("pa\n",1);
}

void	pb(t_stack **a, t_stack **b)
{
	int data;
	data = pop_el(a);
	if (data == 0 && !((*a)->next))
		return ;
	push_el(b, data);
	// ft_putstr_fd("pb\n",1);
}

void	sa(t_stack  **a)
{
	t_stack *first;
	t_stack	*second;
	
	first = (*a);
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
}

void	sb(t_stack **b)
{
	t_stack *first;
	t_stack *second;

	first = (*b);
	second = (*b)->next;
	first->next = second->next;
	second->next = first;
	*b = second;
}

void	ss(t_stack	**a, t_stack **b)
{
	sa(a);
	sb(b);
}

void	ra(t_stack **a)
{
	t_stack *first;
	t_stack *last;

    if (*a == NULL || (*a)->next == NULL)
        return;
    first = (*a)->next;
    last = first;
    while ((last->next) != NULL)
        last = last->next;
	(*a)->next = NULL;
    last->next = *a;
    *a = first;
}

void	rb(t_stack **b)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*b) || !((*b)->next))
		return ;
	first = (*b)->next;
	last = *b;
	while(last->next)
		last = last->next;
	(*b)->next = NULL;
	last->next = (*b);
	(*b) = first;
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

// void	rra(t_stack **a)
// {}

// void	rrb(t_stack **b)
// {}

// void	rrr(t_stack **a, t_stack **b)
// {}