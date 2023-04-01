/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:35:53 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/03/29 13:58:03 by kadigh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_daStack(t_stack **a, t_stack **b, t_vars *variables, int *l_max)
{
	int		n;

	n = (*a)->size - *l_max;
	while(n)
	{
		nqi_liya(a ,b , variables,l_max);
		n--;
	}
}
void	remplir(t_vars *variables, int *l_max, int *max_index, int l)
{
	int	i;
	int	j;

	i = 1;
	while (i <= l)
	{
		j = 0;
		while (j < i)
		{
			if (variables->O_k[j] < variables->O_k[i])
			{
				if (variables->length[i] <= variables->length[j] + 1)
				{
					variables->length[i] = variables->length[j] + 1;
					variables->L[i] = j;
				}
			}
			if (variables->length[j] >= *l_max)
			{
				*l_max = variables->length[j];
				*max_index = j;
			}
			j++;
		}
		i++;
	}
}

void	def_lis(t_stack **a, t_stack **b, t_vars *variables, int l)
{
	int	max_index;
	int	l_max;
	int	i;

	i = 1;
	l_max = variables->length[0];
	remplir(variables, &l_max, &max_index, l);
	variables->p = ft_malloc((l_max + 1) * sizeof(int));
	variables->p[l_max - 1] = max_index;
	while (i < l_max)
	{
		max_index = variables->L[max_index];
		variables->p[l_max - i - 1] = max_index;
		i++;
	}
	clear_daStack(a, b, variables, &l_max);
}

void	retrieve_lis(t_stack **a, t_stack **b, t_vars *variables)
{
	// t_vars	variables;
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	variables->L = ft_malloc((tmp->size + 1) * sizeof(int));
	variables->length = ft_malloc((tmp->size + 1) * sizeof(int));
	while (tmp)
	{
		variables->length[i] = 1;
		variables->L[i] = 0;
		tmp = tmp->next;
		i++;
	}
	def_lis(a, b, variables, i);
}

void	f(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_vars	variables;
	int		i;
	int 	j;

	i = 0;
	j = 0;
	tmp = *a;
	variables.O_k = ft_malloc(((*a)->size + 1) * sizeof(int));
	while (tmp->x != tmp->min)
	{
		i++;
		tmp = tmp->next;
	}
	while(tmp)
	{
		variables.O_k[j++] = tmp->x;
		tmp = tmp->next;
	}
	tmp = *a;
	while (i--)
	{
		variables.O_k[j++] = tmp->x;
		tmp = tmp->next;
	}
	variables.O_k[j] = 0;
	retrieve_lis(a, b, &variables);
}
