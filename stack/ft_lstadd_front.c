/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 04:49:25 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/03/16 11:20:00 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack    **ft_lstadd_front(t_stack **stack, t_stack *node)
{
	t_stack	**head;

	if (*stack && node)
	{
		(*stack)->prev = node;
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
