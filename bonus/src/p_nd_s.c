/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_nd_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:08:35 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/04 16:08:41 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	pa(t_stack **a, t_stack **b)
{
	int	data;

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
}

void	sa(t_stack **a)
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
}

void	sb(t_stack **b)
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
}

void	ss(t_stack	**a, t_stack **b)
{
	sa(a);
	sb(b);
}
