/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:55:56 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/04 21:25:23 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long pop_ele(t_stack **stack)
{
	int	data;
	t_stack	*tmp;

	tmp = (*stack);
	if (!is_empty(stack))
		return (INT32_MAX + 2);
	data = tmp->x;
	*stack = tmp->next;
	(*stack)->size = tmp->size - 1;
	ft_lstiter(*stack, (*stack)->size);
	return (data);
}