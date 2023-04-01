/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 04:49:25 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/03/17 17:09:19 by kadigh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack    **ft_lstadd_front(t_stack **stack, t_stack *node)
{
	t_stack	**head;

	if (*stack && node)
	{
		// (*stack)->prev = node;
		node->next = *stack;
	}
	if (node)
	{
		// node->prev = NULL;
		(*stack) = node;
		head = &node;
		return(head);
	}
	return (stack);
}
