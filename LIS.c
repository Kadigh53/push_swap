/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:35:53 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/03/15 19:53:29 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_itTher(int *p, int *k, int x, int *lmax)
{
	int	i;

	i = 0;
	while(i < *lmax)
	{
		// printf("(%d)[%d]  ",k[p[i]],*lmax);
		if (x == 200)
			printf("lola     %d **",k[p[i]]);
		if (x == k[p[i]]){
			if (x == 200)
				printf("hayi ghid ``\n");
			return (1);
		}
		// printf("%d -",k[p[i]]);
		i++;
	}
	if (x == 200)
		printf("dkhelt hna*\n");
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
		if (i < t)
			ra(a, 1);
		else
			rra(a, 1);
		r_nbrs--;
	}
	printf("%d\n",(*a)->x);
	pb(a,b);
}

void	nqi_liya(int *p, int *k, t_stack **a, t_stack **b, int *l_max)
{
	t_stack	*tmp;
	int		i;
	int		j;
	int		t;
	int		l;
	int		mov;

	i = 0;
	t = 0;
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
		// printf("Hay ghid : /* %d | mov:%d\n",tmp->x, mov);
		tmp = tmp->next;
	}
	// printf("\n");
	j = i;
	while(tmp)//j < ((*a)->size/2))
	{
		if (!is_itTher(p,k,tmp->x,l_max))
		{
			t = ((*a)->size) - j;
			// printf("/* %d : %d */ %d\n",t,tmp->x, ((*a)->size/2));
		}
		tmp = tmp->next;
		j++;
	}
	// printf("(mov:%d,t:%d)\n",mov,t);
	a_to_b(a,b,t,mov);
}

void	clear_daStack(int *p, int *k, t_stack **a, t_stack **b, int *l_max)
{
	// int		i;
	// int 	j;
	int		n;
	// t_stack	*tmp;

	// i = 1;
	// j = 0;
	// ra(a, 1);
	// tmp = *a;
	n = (*a)->size - *l_max;
	while(n)
	{
		nqi_liya(p,k,a,b,l_max);
		n--;
		// if (tmp->x == k[p[i]])
		// {
		// 	ra(a, 1);
		// 	i++;
		// }
		// else
		// {
		// 	pb(a, b);
		// 	n--;
		// }
		// j++;
		// tmp = (*a);
		// nqi_liya(a,b);
		/*
		comparaison between k[p[i]] and k[p[a->size - i]] look to the minumimum and then efectue the 
		least movements of the stack then decide whether you gonna ra OR rra 
		*/
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
			if (k[j] < k[i]) // && length[i] < length[j] + 1
			{
				if (length[i] < length[j] + 1) //length[i] <= length[j] + 1)
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
	p = malloc((l_max + 1) * sizeof(int));
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
	clear_daStack(p, k, a, b, &l_max);
}

void	retrieve_lis(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		*k;
	int		*length;
	int		*kp;
	int		i;

	i = 0;
	tmp = *a;
	k = malloc((tmp->size + 1) * sizeof(int));
	kp = malloc((tmp->size + 1) * sizeof(int));
	length = malloc((tmp->size + 1) * sizeof(int));
	// if (!k || !kp || !length)
	// 	errors ;
	while (tmp)
	{
		k[i] = tmp->x;
		length[i] = 1;
		kp[i] = 0;
		tmp = tmp->next;
		i++;
	}
	def_lis(a, b, k, length, kp, i);
}

void	f(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	while (tmp->x != tmp->min)
	{
		i++;
		tmp = tmp->next;
	}
	while ((*a)->x != (*a)->min)
	{
		if (i > (*a)->size / 2)
			rra(a, 1);
		else
			ra(a, 1);
	}
	retrieve_lis(a, b);
}
