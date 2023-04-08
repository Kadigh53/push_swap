/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_construction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 05:44:09 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/08 01:20:57 by kadigh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"







// long	pop_el(t_stack **stack)
// {
// 	long	data;
// 	t_stack	*tmp;

// 	tmp = (*stack);
// 	if (!is_empty(stack))
// 		return (2147483647 + 2);
// 	data = tmp->x;
// 	((*stack)->next)->size = tmp->size - 1;
// 	*stack = tmp->next;
// 	ft_lstiter(*stack, (*stack)->size);
// 	return (data);
// }

void	init_init(int *k, int *l, t_stack **stack)
{
	int	min;
	int	max;
	int	i;

	i = 0;
	min = k[0];
	max = k[0];
	while (i < *l)
	{
		if (k[i] < min)
			min = k[i];
		if (k[i] > max)
			max = k[i];
		i++;
	}
	(*stack)->min = min;
	(*stack)->max = max;
	(*stack)->next = NULL;
	(*stack)->size = 0;
	(*stack)->x = 0;
}

void	stack_init(int *k, t_stack **A, t_stack **B, int *l)
{
	int	i;

	i = 0;
	*A = ft_malloc(sizeof(t_stack));
	*B = ft_malloc(sizeof(t_stack));
	init_init(k, l, A);
	init_init(k, l, B);
	while (i < *l)
	{
		push_el(A, k[*l - i - 1], (*A)->min, (*A)->max);
		i++;
	}
}
