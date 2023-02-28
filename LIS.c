/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:35:53 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/28 08:33:32 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	def_lis(t_stack **a,int *k,int *length, int *kp, int *l)
{
	int	i;
	int	j;
	int l_max;
	int max_index;

	i = 1;
	l_max = length[0];
	while (i < *l)
	{
		j = 0;
		while(j < i)
		{
			if (k[j] < k[i])
			{
				if (length[i] < length[j] + 1)
				{
					length[i] = length[j] + 1;
					kp[i] = j;
				}
			}
			if (length[j] > l_max)
			{
				l_max = length[j];
				max_index = j;
			}
			j++;
		}
		i++;
	}
	int *p = malloc((l_max + 1) * sizeof(int));
	// if (!p)
	// 	error ;
	i = 1;
	p[l_max - 1] = max_index;
	while (i < l_max)
	{
		max_index = kp[max_index];
		p[l_max - i - 1] = max_index;
		i++;
	}
	i = 0;
	j = 0;
	while (i < l_max)
	{
		if ((p[i] - p[i + 1]) > 1)
			clear_daStack(p,a);
	}
	
}

void clear_daStackAction(t_stack **a, int Rnbr, int r)
{}

void	clear_daStack(int *p, t_stack **a, int l_max)
{
	int i;

	i = 0;
	while ()
	{
		if ((p[i + 1] - p[i]) < 1)
		{
			if ((p[i] + 1) > ((*a)->size - p[i + 1] - 1))
			
			else 
		}
		i++;
	}
}

void	retrieve_lis(t_stack **a)
{
	t_stack	*tmp;
	int		*k;
	int		*length;
	int		*kp;
	int	i;
	
	i = 0;
	tmp = *a;
	k = malloc((tmp->size + 1) * sizeof(int));
	kp = malloc((tmp->size + 1) * sizeof(int));
	length = malloc((tmp->size + 1) * sizeof(int));
	if (!k || !kp || !length)
		errors ;
	while (tmp)
	{
		k[i] = tmp->x;
		length[i] = 1;
		kp[i] = 0;
		tmp = tmp->next;
	}
	def_lis(k, length, kp,l);
}

void f(t_stack **a)
{
	t_stack *tmp;
	int	i;

	i = 0;
	tmp = *a;
	while (tmp->x != tmp->min)
	{
		i++;
		tmp = tmp->next;
	}
	while ((*a)->x != (*a)->min)
	{
		if (i >= (*a)->size/2)
			rra(a);
		else   
		    ra(a);
	}
}
