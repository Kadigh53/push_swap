/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_construction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 05:44:09 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/04 19:51:39 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstiter(t_stack *stack, int s)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (tmp)
	{
		tmp->size = s;
		tmp = tmp->next;
		i++;
	}
}

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

int	pop_el(t_stack **stack, t_stack **a)
{
	t_stack	*tmp;
	int		data;

	if (!(*stack)->next && ((*stack)->size == 0))
		return (0);
	if (!(*stack)->next && ((*stack)->size == 1))
	{
		data = (*stack)->x;
		(*stack)->x = 0;
		(*stack)->size = 0;
		if (data == 0)
			push_el(a, data, (*a)->min, (*a)->max);
		return (data);
	}
	data = (*stack)->x;
	tmp = (*stack);
	((*stack)->next)->size = tmp->size - 1;
	*stack = ((*stack)->next);
	// tmp1 = &(*stack)->next;
	// free(*stack);
	// stack = tmp1;
	ft_lstiter(*stack, (*stack)->size);
	// free(tmp);
	return (data);
}

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
