/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_construction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 05:44:09 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/02 00:29:04 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

int	is_empty(t_stack *stack)
{
	if (stack->size == 0 && !stack->next)
		return (1);
	return (0);
}

void	ft_lstiter(t_stack *stack, int s)
{
	t_stack	*tmp;
	int	i =0;
	// if (stack)
	// 	return ;
	tmp = stack;
	while (tmp)
	{
		tmp->size = s;
		tmp = tmp->next;
		i++;
	}
}

void    push_el(t_stack **stack, int data, int min, int max)
{
	t_stack	*node;

	if ((!(*stack)->next && (*stack)->size == 0 && (*stack)->x == 0))
	{
		(*stack)->x = data;
		(*stack)->min = min;
		(*stack)->max = max;
		(*stack)->size = 1;
		// (*stack)->prev = NULL;
		(*stack)->next = NULL;
		return ;
	}
	node = ft_lstnew(data, min, max);
	stack = ft_lstadd_front(stack,node);
	(*stack)->size = ((*stack)->next)->size + 1;
	ft_lstiter(*stack, (*stack)->size);
}

int	pop_el(t_stack **stack, t_stack **a)
{
	int data;
	t_stack	*tmp;

	if (is_empty(*stack))
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
	ft_lstiter(*stack, (*stack)->size);
	return (data);
}

void	init_init(int *k,  int *l, t_stack **stack)
{
	int min;
	int max;
	int i;

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
	int i;

	i = 0;
	*A = malloc(sizeof(t_stack));
	if (!*A)
		exit(1);
	*B = malloc(sizeof(t_stack));
	if (!*B)
		exit(1);
	init_init(k, l, A);
	init_init(k, l, B);
	while(i < *l)
	{
		push_el(A,k[*l - i - 1], (*A)->min, (*A)->max);
		i++;
	}
}
