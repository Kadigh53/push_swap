/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:35:53 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/03/23 23:48:08 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_itTher(int *p, int *k, int x, int *lmax)
{
	int	i;

	i = 0;
	while(i < *lmax)
	{
		if (x == k[p[i]])
			return (1);
		i++;
	}
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

void	nqi_liya(int *p, int *k, t_stack **a, t_stack **b, int *l_max)
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
		if (!is_itTher(p,k,tmp->x,l_max) && l)
		{
			l--;
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
		if (!is_itTher(p,k,tmp->x,l_max))
			t = ((*a)->size) - i;
		tmp = tmp->next;
		i++;
	}
	a_to_b(a,b,t,mov);
}

void	clear_daStack(int *p, int *k, t_stack **a, t_stack **b, int *l_max)
{
	int		n;

	n = (*a)->size - *l_max;
	while(n)
	{
		nqi_liya(p,k,a,b,l_max);
		n--;
	}
}

void	def_lis(t_stack **a, t_stack **b, int *k, int *length, int *kp, int l)
{
	int	i;
	int	j;
	int	l_max;
	int	max_index;
	int	*p;

	i = 1;
	l_max = length[0];
	while (i <= l)
	{
		j = 0;
		while (j < i)
		{
			if (k[j] < k[i])
			{
				if (length[i] <= length[j] + 1)
				{
					length[i] = length[j] + 1;
					kp[i] = j;
				}
			}
			if (length[j] >= l_max)
			{
				l_max = length[j];
				max_index = j;
			}
			j++;
		}
		i++;
	}
	p = malloc((l_max + 1) * sizeof(int));
	if (!p)
		errors("Malloc failed");
	i = 1;
	p[l_max - 1] = max_index;
	while (i < l_max)
	{
		max_index = kp[max_index];
		p[l_max - i - 1] = max_index;
		i++;
	}
	clear_daStack(p, k, a, b, &l_max);
}

void	retrieve_lis(t_stack **a, t_stack **b, int *k)
{
	t_stack	*tmp;
	int		*length;
	int		*L;
	int		i;
	// int		j;

	i = 0;
	tmp = *a;
	L = malloc((tmp->size + 1) * sizeof(int));
	length = malloc((tmp->size + 1) * sizeof(int));
	if (!L || !length)
		errors("Malloc failed ") ;
	while (tmp)
	{
		length[i] = 1;
		L[i] = 0;
		tmp = tmp->next;
		i++;
	}
	def_lis(a, b, k, length, L, i);
}

void	f(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		*k;
	int		i;
	int 	j;

	i = 0;
	j = 0;
	tmp = *a;
	k = malloc(((*a)->size + 1) * sizeof(int));
	if (!k)
		errors("Malloc failed ");
	while (tmp->x != tmp->min)
	{
		i++;
		tmp = tmp->next;
	}
	while(tmp)
	{
		k[j] = tmp->x;
		j++;
		tmp = tmp->next;
	}
	tmp = *a;
	while (i)
	{
		k[j++] = tmp->x;
		// j++;
		i--;
		tmp = tmp->next;
	}
	k[j] = 0;
	retrieve_lis(a, b, k);
}

// void *ft_malloc(int size) {
// 	void *buff = malloc(size);
// 	if (!buff) {
// 		errorss("mele;m");
// 		exit(EXIT_FAILURE);
// 	}
// 	return buff
// }