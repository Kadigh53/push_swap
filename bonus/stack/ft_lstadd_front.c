/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 04:49:25 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/10 23:32:52 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

t_stack	**ft_lstadd_front(t_stack **stack, t_stack *node)
{
	t_stack	**head;

	// if (*stack && node)
	// {
	// }
	if (node)
	{
		node->next = *stack;
		(*stack) = node;
		head = &node;
		return (head);
	}
	return (stack);
}
