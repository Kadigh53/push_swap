/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:55:18 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/04 15:55:25 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack **a, int mode)
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
	if (mode == 1)
		ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b, int mode)
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
	if (mode == 1)
		ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_putstr_fd("rrr\n", 1);
}
