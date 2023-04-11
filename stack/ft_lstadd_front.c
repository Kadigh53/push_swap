/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 04:49:25 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/11 02:04:52 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	**ft_lstadd_front(t_stack **stack, t_stack *node)
{
	t_stack	**head;

	if (node)
	{
		node->next = *stack;
		(*stack) = node;
		head = &node;
		return (head);
	}
	return (stack);
}
