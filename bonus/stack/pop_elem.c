/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:55:56 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/10 23:33:07 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"


// int	pop_el(t_stack **stack, t_stack **a)
// {
// 	t_stack	*tmp;
// 	int		data;

// 	if (!(*stack)->next && ((*stack)->size == 0))
// 		return (0);
// 	if (!(*stack)->next && ((*stack)->size == 1))
// 	{
// 		data = (*stack)->x;
// 		(*stack)->x = 0;
// 		(*stack)->size = 0;
// 		if (data == 0)
// 			push_el(a, data, (*a)->min, (*a)->max);
// 		return (data);
// 	}
// 	data = (*stack)->x;
// 	tmp = (*stack);
// 	((*stack)->next)->size = tmp->size - 1;
// 	*stack = ((*stack)->next);
// 	ft_lstiter(*stack, (*stack)->size);
// 	free(tmp);
// 	return (data);
// }

t_stack	*pop_el(t_stack **stack)
{
	int data;
	t_stack	*tmp;

	if (!(*stack))
		return (NULL);
	data = (*stack)->x;
	tmp = *stack;
	if (!(*stack)->next)
		(*stack)->size = 1;
	else
	{
		((*stack)->next)->size = tmp->size - 1;
		ft_lstiter(*stack, (*stack)->size);
	}
	*stack = ((*stack)->next);
	// (*tmp)->next = NULL;
	return (tmp);
}

// long pop_ele(t_stack **stack)
// {
// 	int	data;
// 	t_stack	*tmp;

// 	tmp = (*stack);
// 	if (!is_empty(stack))
// 		return (INT32_MAX + 2);
// 	data = tmp->x;
// 	*stack = tmp->next;
// 	(*stack)->size = tmp->size - 1;
// 	ft_lstiter(*stack, (*stack)->size);
// 	return (data);
// }