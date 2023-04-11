/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:55:43 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/11 04:33:46 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_itther(t_vars *var, int x, int *lmax)
{
	int	i;

	i = 0;
	while (i < *lmax)
	{
		if (x == var->o_k[var->p[i]])
			return (1);
		i++;
	}
	return (0);
}

void	a_to_b(t_stack **a, t_stack **b, int t, int i)
{
	int	r_nbrs;

	r_nbrs = i;
	if (i > t)
		r_nbrs = t;
	while (r_nbrs)
	{
		if (i <= t)
			ra(a, 1);
		else
			rra(a, 1);
		r_nbrs--;
	}
	pb(a, b);
}

int	upper_moves(t_stack **tmp, t_stack **a, t_vars *var, int *l_max)
{
	int	i;
	int	l;
	int	r_mov;

	i = 0;
	l = 1;
	while (i <= ((*a)->size) / 2)
	{
		if (!is_itther(var, (*tmp)->x, l_max) && l)
		{
			l--;
			r_mov = i;
		}
		i++;
		*tmp = (*tmp)->next;
	}
	if (l == 1)
		r_mov = ((*a)->size);
	return (r_mov);
}

void	nqi_liya(t_stack **a, t_stack **b, t_vars *var, int *l_max)
{
	t_stack	*tmp;
	int		r_mov;
	int		i;
	int		rr_mov;

	i = 0;
	rr_mov = (*a)->size;
	tmp = *a;
	i = (((*a)->size) / 2) + 1;
	r_mov = upper_moves(&tmp, a, var, l_max);
	while (tmp)
	{
		if (!is_itther(var, tmp->x, l_max))
			rr_mov = ((*a)->size) - i;
		tmp = tmp->next;
		i++;
	}
	a_to_b(a, b, rr_mov, r_mov);
}

	// while (i <= ((*a)->size) / 2)
	// {
	// 	if (!is_itther(var, tmp->x, l_max) && l)
	// 	{
	// 		l--;
	// 		r_mov = i;
	// 	}
	// 	i++;
	// 	tmp = tmp->next;
	// }
	// if (l == 1)
	// 	r_mov = ((*a)->size);