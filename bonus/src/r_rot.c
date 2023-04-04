/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:09:14 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/04 16:09:41 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	rra(t_stack **a)
{
	t_stack	*tmp;
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
