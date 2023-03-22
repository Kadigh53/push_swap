/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LIS.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:35:53 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/03/22 17:41:44 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_itTher(int *p, int *k, int x, int *lmax)
{
	int	i;

	i = 0;
	while(i < *lmax)
	{
		if (x == k[p[i]]){
			// printf("%d kayn\n",x);
			return (1);
		}
		i++;
	}
	// printf("%d makaynch\n",x);
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
	// t_stack *tmp = *a;
	// while (tmp)
	// {
	// 	printf("a    %d\n", tmp->x);
	// 	tmp = tmp->next;
	// }
	// printf("%d\n",(*a)->x);
	pb(a,b);
	// printf("\n");
}

void	nqi_liya(int *p, int *k, t_stack **a, t_stack **b, int *l_max)
{
	t_stack	*tmp;
	int		i;
	int		t;
	int		l;
	int		mov;

	i = 0;
	// t = 0;
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
		{
			t = ((*a)->size) - i;
			// printf("/* %d : %d */ %d\n",t,tmp->x, ((*a)->size/2));
		}
		tmp = tmp->next;
		i++;
	}
	// printf("\n(mov:%d,t:%d)\n\n",mov,t);
	a_to_b(a,b,t,mov);
}

void	clear_daStack(int *p, int *k, t_stack **a, t_stack **b, int *l_max)
{
	int		n;

	n = (*a)->size - *l_max;
	// printf(">>>>>>%d   %d  %d \n\n",(*a)->size,*l_max ,n);
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
			if (k[j] < k[i]) // && length[i] < length[j] + 1
			{
				if (length[i] <= length[j] + 1) //length[i] <= length[j] + 1)
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

void	retrieve_lis(t_stack **a, t_stack **b, int *k)
{
	t_stack	*tmp;
	// int		*k;
	int		*length;
	int		*L;
	int		i;
	int		j;

	// i = 0;
	// while (i < 18){
	// 	printf(">>%d  ",k[i]);
	// 	i++;
	// }
	i = 0;
	tmp = *a;
	L = malloc((tmp->size + 1) * sizeof(int));
	length = malloc((tmp->size + 1) * sizeof(int));
	// if (!k || !kp || !length)
	// 	errors ;
	while (tmp)
	{
		length[i] = 1;
		L[i] = 0;
		tmp = tmp->next;
		i++;
	}
	j = 0;
	// printf("\n");
	// while (j<17){
	// 	printf("%d  >>",k[j]);
	// 	j++;
	// }
	// printf("\n");
	// printf("\n%D",(*b)->size);
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
	// printf("\nsize : %d\t",(*a)->size);
	tmp = *a;
	k = malloc(((*a)->size + 1) * sizeof(int));
	// if (!k)
	// 	error()
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
		k[j] = tmp->x;
		// printf("%d  ",tmp->x);
		j++;
		i--;
		tmp = tmp->next;
	}
	k[j] = 0;
	retrieve_lis(a, b, k);
	// while (i <17)
	// {
	// 	printf("%d  ",k[i++]);
	// }
	// printf("\n");
	
	// tmp = *b;
	// while ((*a)->x != (*a)->min)
	// {
	// 	if (i > (*a)->size / 2)
	// 		rra(a, 1);
	// 	else
	// 		ra(a, 1);
	// }


	
	// tmp = *a;
	// printf("after a_to_b\n");
	// while (tmp){
	// 	printf("a %d\n",tmp->x);
	// 	tmp = tmp->next;
	// }
	// printf("\n");
}