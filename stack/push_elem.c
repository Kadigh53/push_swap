/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:56:15 by kadigh            #+#    #+#             */
/*   Updated: 2023/04/08 00:57:09 by kadigh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_el(t_stack **stack, int data, int min, int max)
{
	t_stack	*node;

	if ((!(*stack)->next && (*stack)->size == 0 && (*stack)->x == 0))
	{
		(*stack)->x = data;
		(*stack)->min = min;
		(*stack)->max = max;
		(*stack)->size = 1;
		(*stack)->next = NULL;
		return ;
	}
	node = ft_lstnew(data, min, max);
	stack = ft_lstadd_front(stack, node);
	(*stack)->size = ((*stack)->next)->size + 1;
	ft_lstiter(*stack, (*stack)->size);
}