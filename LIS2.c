/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:55:43 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/03 19:44:24 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	*ft_malloc(int size)
{
	void	*buff;

	buff = malloc(size);
	if (!buff)
		errors("Malloc failed");
	return (buff);
}

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

void	nqi_liya(t_stack **a, t_stack **b, t_vars *var, int *l_max)
{
	t_stack	*tmp;
	int		mov;
	int		i;
	int		t;
	int		l;

	i = 0;
	l = 1;
	t = (*a)->size;
	tmp = *a;
	while (i <= ((*a)->size) / 2)
	{
		if (!is_itther(var, tmp->x, l_max) && l)
		{
			l--;
			mov = i;
			// printf("");
		}
		i++;
		tmp = tmp->next;
	}
	if (l == 1){
		// printf("hayi ghod   ");
		mov = ((*a)->size);
	}
	// printf(">> ra : %d  ",mov);
	while (tmp)
	{
		if (!is_itther(var, tmp->x, l_max))
			t = ((*a)->size) - i;
		tmp = tmp->next;
		i++;
	}
	// printf(" rra : %d\n",t);
	a_to_b(a, b, t, mov);
}
