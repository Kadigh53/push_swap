/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_elem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:55:56 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/11 02:11:15 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

t_stack	*pop_el(t_stack **stack)
{
	t_stack	*tmp;

	if (!(*stack))
		return (NULL);
	tmp = *stack;
	if (!(*stack)->next)
		(*stack)->size = 1;
	else
	{
		((*stack)->next)->size = tmp->size - 1;
		ft_lstiter(*stack, (*stack)->size);
	}
	*stack = ((*stack)->next);
	return (tmp);
}
