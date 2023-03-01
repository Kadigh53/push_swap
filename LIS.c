/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:35:53 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/03/01 08:56:03 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_daStackAction(t_stack **a, t_stack **b, int Rnbr, int Pnbr, int r)
{
	int	i;

	i = 0;
	printf("clear_stackAction Rnbr : %d. Pnbr : %d\n", Rnbr, Pnbr);
	while (i < Rnbr)
	{
		if (r == 0)
			ra(a);
		else if (r == 1)
			rra(a);
		i++;
	}
	i = 0;
	while (i < Pnbr)
	{
		pb(a, b);
		i++;
	}
}

void	clear_daStack(int *p, t_stack **a, t_stack **b, int l_max)
{
	int		i;
	int		rot;
	int		push;
	int 	t;
	t_stack	*tmp1;

	i = 0;
	rot = 0;
	push = 0;
	tmp1 = *a;
	while (i < l_max)
	{
		// printf("p[i]:%d\tp[i+1]:%d\t( - )%d\n", p[i], p[i + 1], p[i + 1]
				// - p[i]);
		t = rot + push;
		if ((p[i + 1] - p[i]) > 1)
		{
			rot = p[i] + 1 - t;
			push = p[i + 1] - p[i] - 1;
			// printf("rot : %d\t push : %d\tt : %d\n",rot , push ,t);
			// if ((p[i] + 1) > ((*a)->size - p[i + 1] - 1))
			// 	clear_daStackAction(a, b, rot, push, 0);
			// else
			clear_daStackAction(a, b, rot, push, 0);
			t = rot + push;
			tmp1 = *a;
			while (tmp1)
			{
				printf("a %d\t\n", tmp1->x);
				tmp1 = tmp1->next;
			}
		}
		i++;
	}
	tmp1 = *a;
	printf("\n====5%d=======\n",t);
	while (tmp1)
	{
		printf("a %d\t\n", tmp1->x);
		tmp1 = tmp1->next;
	}
	// printf("\npi:%d\n",p[i-1]);
	clear_daStackAction(a, b, (*a)->size - p[i - 1] + 1, 0, 0);
	tmp1 = *a;
	printf("\n====2=======\n");
	while (tmp1)
	{
		printf("a %d\t\n", tmp1->x);
		tmp1 = tmp1->next;
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
	while (i < l)
	{
		j = 0;
		while (j < i)
		{
			if (k[j] < k[i]) // && length[i] < length[j] + 1
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
	// i = 0;
	// j = 0;
	// while (i < l_max)
	// {
	// 	if ((p[i + 1] - p[i]) > 1)
	// 		clear_daStack(p,a, l_max);
	// }
	clear_daStack(p, a, b, l_max);
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
	t_stack	*tmp1;

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
			rra(a);
		else
			ra(a);
	}
	tmp1 = *a;
	i = 0;
	while (tmp1)
	{
		printf("a %d\t %d\t\n", i, tmp1->x);
		tmp1 = tmp1->next;
		i++;
	}
	printf("\n");
	retrieve_lis(a, b);
}
