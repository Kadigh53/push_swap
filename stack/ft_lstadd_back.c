/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 05:10:16 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/24 06:33:13 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void    ft_lstadd_back(t_stack  **stack, t_stack *node)
// {
// 	t_stack *tmp;
	
// 	tmp = (*stack);
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	tmp = node;
// }

void	ft_lstadd_back(t_stack  **stack, t_stack *node)
{
	t_stack	*tmp;

	tmp = (*stack);
	if (node)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
	else
		*stack = node;
}