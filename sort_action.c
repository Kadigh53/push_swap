/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:03:18 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/11 06:40:36 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(int e_pos[2], int mr, t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (i < ft_abs(e_pos[0]) - mr)
	{
		if (e_pos[0] < 0)
			rra(a, 1);
		else if (e_pos[0] > 0)
			ra(a, 1);
		i++;
	}
	i = 0;
	while (i < ft_abs(e_pos[1]) - mr)
	{
		if (e_pos[1] < 0)
			rrb(b, 1);
		else if (e_pos[1] > 0)
			rb(b, 1);
		i++;
	}
	pa(a, b);
}

void	b_to_a(int e_pos[2], t_stack **a, t_stack **b)
{
	int	k;
	int	mr;

	k = 0;
	mr = 0;
	if ((e_pos[1] * e_pos[0]) > 0)
	{
		mr = ft_min(ft_abs(e_pos[0]), ft_abs(e_pos[1]));
		k = ft_min(ft_abs(e_pos[0]), ft_abs(e_pos[1]));
	}
	while (mr)
	{
		if ((e_pos[0] > 0) && (e_pos[1] > 0))
			rr(a, b);
		else
			rrr(a, b);
		mr--;
	}
	rotate(e_pos, k, a, b);
}

void	sort_action(int e_pos[][2], t_stack **a, t_stack **b)
{
	int			i;
	t_s_vars	vars;
	t_stack		*tmp;

	i = 0;
	tmp = *b;
	vars.min = ft_abs(e_pos[0][0]) + ft_abs(e_pos[0][1]);
	vars.index = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
		vars.mvs = ft_abs(e_pos[i][0]) + ft_abs(e_pos[i][1]);
		if (vars.mvs < vars.min && i <= ((*b)->size / 2))
		{
			vars.min = vars.mvs;
			vars.index = i;
		}
		else if (vars.mvs <= vars.min && i > ((*b)->size / 2))
		{
			vars.min = vars.mvs;
			vars.index = i;
		}
	}
	b_to_a(e_pos[vars.index], a, b);
}

int	locate_damax(t_stack **a)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		if ((tmp->x == (*a)->min) && i <= ((*a)->size / 2))
			return (i);
		else if ((tmp->x == (*a)->min) && i > ((*a)->size / 2))
			return (i - (*a)->size);
		i++;
		tmp = tmp->next;
	}
	return ((*a)->size);
}
