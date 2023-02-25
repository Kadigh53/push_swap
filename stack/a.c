/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 05:44:09 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/25 02:40:26 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
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

void    push_el(t_stack **stack, int data)
{
	t_stack	*node;

	if ((!(*stack)->next && (*stack)->size == 0 && (*stack)->x == 0))
	{
		(*stack)->x = data;
		(*stack)->size = 1;
		(*stack)->next = NULL;
		return ;
	}
	node = ft_lstnew(data);
	stack = ft_lstadd_front(stack,node);
	(*stack)->size = ((*stack)->next)->size + 1;
	ft_lstiter(*stack, (*stack)->size);
}

int	pop_el(t_stack **stack)
{
	int data;
	t_stack	*tmp;

	if (is_empty(*stack))
		return (0);
	data = (*stack)->x;
	tmp = (*stack);
	((*stack)->next)->size = tmp->size - 1;
	*stack = ((*stack)->next);
	free(tmp);
	ft_lstiter(*stack, (*stack)->size);
	return (data);
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
	(*A)->next = NULL;
	(*B)->next = NULL;
	(*A)->size = 0;
	(*B)->size = 0;
	(*A)->x = 0;
	(*B)->x = 0;
	while(i < *l)
	{
		push_el(A,k[*l - i - 1]);
		i++;
	}
}
