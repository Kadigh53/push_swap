/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:54:08 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/04 16:05:49 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stack **a, int mode)
{
	t_stack	*first;
	t_stack	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = (*a)->next;
	last = first;
	while ((last->next) != NULL)
	{
		last = last->next;
	}
	(*a)->next = NULL;
	last->next = *a;
	*a = first;
	if (mode == 1)
		ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b, int mode)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*b) || !((*b)->next))
		return ;
	first = (*b)->next;
	last = *b;
	while (last->next)
		last = last->next;
	(*b)->next = NULL;
	last->next = (*b);
	(*b) = first;
	if (mode == 1)
		ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	ft_putstr_fd("rr\n", 1);
}
