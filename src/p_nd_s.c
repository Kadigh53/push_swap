/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_nd_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:53:32 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/04 16:05:42 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	int	data;

	ft_putstr_fd("pa\n", 1);
	data = pop_el(b, a);
	if (data == 0 && !((*b)->next) && ((*b)->size == 0))
		return ;
	push_el(a, data, (*a)->min, (*a)->max);
}

void	pb(t_stack **a, t_stack **b)
{
	int	data;

	data = pop_el(a, a);
	if (data == 0 && !((*a)->next) && ((*b)->size) == 0)
		return ;
	push_el(b, data, (*b)->min, (*b)->max);
	ft_putstr_fd("pb\n", 1);
}

void	sa(t_stack	**a, int mode)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*a)->next)
		return ;
	first = (*a);
	second = (*a)->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	if (mode == 1)
		ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b, int mode)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*b)->next)
		return ;
	first = (*b);
	second = (*b)->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	if (mode == 1)
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack	**a, t_stack **b)
{
	sa(a, 0);
	sb(b, 0);
	ft_putstr_fd("ss\n", 1);
}
