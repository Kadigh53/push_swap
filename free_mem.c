/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:58:33 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/11 02:21:03 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **a)
{
	t_stack	*tmp;

	while ((*a))
	{
		tmp = (*a)->next;
		free(*a);
		(*a) = tmp;
	}
	free(*a);
}

void	free_mem(t_vars *vars)
{
	free(vars->k);
	free(vars->o_k);
	free(vars->le);
	free(vars->length);
	free(vars->p);
	free_stack(&vars->a);
	free_stack(&vars->b);
}
