/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:35:53 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/11 01:59:58 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_dastack(t_stack **a, t_stack **b, t_vars *var, int *l_max)
{
	int		n;

	n = (*a)->size - *l_max;
	while (n)
	{
		nqi_liya(a, b, var, l_max);
		n--;
	}
}

void	remplir(t_vars *var, int *l_max, int *max_index, int l)
{
	int	i;
	int	j;

	i = 1;
	while (i <= l)
	{
		j = 0;
		while (j++ < i)
		{
			if (var->o_k[j - 1] <= var->o_k[i])
			{
				if (var->length[i] <= var->length[j - 1] + 1)
				{
					var->length[i] = var->length[j - 1] + 1;
					var->le[i] = j - 1;
				}
			}
			if (var->length[j - 1] >= *l_max)
			{
				*l_max = var->length[j - 1];
				*max_index = j - 1;
			}
		}
		i++;
	}
}

void	def_lis(t_stack **a, t_stack **b, t_vars *var, int l)
{
	int	max_index;
	int	l_max;
	int	i;

	i = 1;
	l_max = var->length[0];
	remplir(var, &l_max, &max_index, l);
	var->p = ft_malloc((l_max + 1) * sizeof(int));
	var->p[l_max - 1] = max_index;
	while (i < l_max)
	{
		max_index = var->le[max_index];
		var->p[l_max - i - 1] = max_index;
		i++;
	}
	clear_dastack(a, b, var, &l_max);
	// free(var->p);
}

void	retrieve_lis(t_stack **a, t_stack **b, t_vars *var)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	var->le = ft_malloc((tmp->size + 1) * sizeof(int));
	var->length = ft_malloc((tmp->size + 1) * sizeof(int));
	while (tmp)
	{
		var->length[i] = 1;
		var->le[i] = 0;
		tmp = tmp->next;
		i++;
	}
	def_lis(a, b, var, i);
}

void	f(t_stack **a, t_stack **b, t_vars *var)
{
	t_stack	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = *a;
	var->o_k = ft_malloc(((*a)->size + 1) * sizeof(int));
	while (tmp->x != tmp->min)
	{
		i++;
		tmp = tmp->next;
	}
	while (tmp)
	{
		var->o_k[j++] = tmp->x;
		tmp = tmp->next;
	}
	tmp = *a;
	while (i--)
	{
		var->o_k[j++] = tmp->x;
		tmp = tmp->next;
	}
	retrieve_lis(a, b, var);
}
