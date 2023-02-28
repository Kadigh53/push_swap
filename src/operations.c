/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 08:14:17 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/28 00:37:56 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	int data;
	data = pop_el(b);
	if (data == 0 && !((*b)->next))
		return ;
	push_el(a, data, (*a)->min, (*a)->max);
	// ft_putstr_fd("pa\n",1);
}

void	pb(t_stack **a, t_stack **b)
{
	int data;
	data = pop_el(a);
	if (data == 0 && !((*a)->next))
		return ;
	push_el(b, data, (*b)->min, (*b)->max);
	// ft_putstr_fd("pb\n",1);
}

void	sa(t_stack  **a)
{
	t_stack *first;
	t_stack	*second;

	if (!(*a)->next)
		return ;
	first = (*a);
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	// ft_putstr_fd("sa\n",1);
}

void	sb(t_stack **b)
{
	t_stack *first;
	t_stack *second;

	if (!(*b)->next)
		return ;
	first = (*b);
	second = (*b)->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	// ft_putstr_fd("sb\n",1);
}

void	ss(t_stack	**a, t_stack **b)
{
	sa(a);
	sb(b);
	// ft_putstr_fd("pa\n",1);
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

void	rra(t_stack **a)
{
	t_stack *tmp;
	t_stack	*head;

	tmp = (*a);
	if (!tmp->next)
		return ;
	while ((tmp->next)->next)
		tmp = tmp->next;
	head = tmp->next;
	head->next = (*a);
	tmp->next = NULL;
	(*a) = head;
	
}

void	rrb(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*head;

	if (!(*b)->next)
		return ;
	tmp = (*b);
	while ((tmp->next)->next)
		tmp = tmp->next;
	head = tmp->next;
	head->next = (*b);
	tmp->next = NULL;
	(*b) = head;	
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}