/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:56:15 by kadigh            #+#    #+#             */
/*   Updated: 2023/04/10 23:33:11 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	push_el(t_stack **stack, int data, int min, int max)
{
	t_stack	*node;

	// if ((!(*stack)->next && (*stack)->size == 0 && (*stack)->x == 0))
	// {
	// 	(*stack)->x = data;
	// 	(*stack)->min = min;
	// 	(*stack)->max = max;
	// 	(*stack)->size = 1;
	// 	(*stack)->next = NULL;
	// 	return ;
	// }
	node = ft_lstnew(data, min, max);
	if (!(*stack))
		node->size = 1;
	else
		node->size = (*stack)->size + 1;
	stack = ft_lstadd_front(stack, node);
	// (*stack)->size = ((*stack)->next)->size + 1;
	ft_lstiter(*stack, node->size);
}