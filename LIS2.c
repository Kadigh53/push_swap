/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:55:43 by aaoutem-            #+#    #+#             */
/*   Updated: 2023/03/29 14:00:52 by aaoutem-           ###   ########.fr       */
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
	void *buff;

	buff = malloc(size);
	if (!buff)
		errors("Malloc failed");
	return (buff);
}

int	is_itTher(t_vars *variables, int x, int *l, int *lmax)
{
	int	i;

	i = 0;
	*l = 1;
	while(i < *lmax)
	{
		if (x == variables->O_k[variables->p[i]])
			return (1);
		i++;
	}
	*l = 0;
	return (0);
}

void	a_to_b(t_stack **a, t_stack **b, int t, int i)
{
	int r_nbrs;

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
	pb(a,b);
}

void	nqi_liya(t_stack **a, t_stack **b, t_vars *variables, int *l_max)
{
	t_stack	*tmp;
	int		i;
	int		t;
	int		l;
	int		mov;

	i = 0;
	l = 1;
	tmp = *a;
	while (i <= ((*a)->size) / 2)
	{
		if (!is_itTher(variables,tmp->x,&l,l_max) && l)
		{
			// l--;
			mov = i;
		}
		i++;
		tmp = tmp->next;
	}
	if (l == 1)
		mov = ((*a)->size);
	t = (*a)->size;
	while(tmp)
	{
		if (!is_itTher(variables,tmp->x,&l,l_max))
			t = ((*a)->size) - i;
		tmp = tmp->next;
		i++;
	}
	a_to_b(a,b,t,mov);
}