/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 04:49:25 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/02 19:45:59 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

t_stack	**ft_lstadd_front(t_stack **stack, t_stack *node)
{
	t_stack	**head;

	if (*stack && node)
	{
		node->next = *stack;
	}
	if (node)
	{
		(*stack) = node;
		head = &node;
		return (head);
	}
	return (stack);
}
