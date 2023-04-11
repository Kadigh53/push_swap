/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 05:10:16 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/10 23:32:46 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

// void    ft_lstadd_back(t_stack  **stack, t_stack *node)
// {
// 	t_stack *tmp;
// 	tmp = (*stack);
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	tmp = node;
// }

void	ft_lstadd_back(t_stack	**stack, t_stack *node)
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
