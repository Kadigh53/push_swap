/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 02:27:28 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/03/05 02:11:34 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int a)
{
	if (a < 0)
		a = a * (-1);
	return (a);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	b_to_a(int e_pos[2], t_stack **a, t_stack **b)
{
	int	i;
	int rot_a;
	int	rot_b;
	int mr;

	i = 0;
	mr = 0;
	rot_a = ft_abs(e_pos[0]);
	rot_b = ft_abs(e_pos[1]);
	if ((e_pos[1] * e_pos[0]) > 0)
		mr = ft_min(rot_a, rot_b);
	while (mr)
	{
		if ((e_pos[0] > 0) && (e_pos[1] > 0))
			rr(a, b);
		else
			rrr(a,b);
		mr--;
	}
	while (i < rot_a - mr)
	{
		if (e_pos[1] < 0)
			rra(a);
		else
			ra(a);
		i++;
	}
	i = 0;
	while (i < rot_b - mr)
	{
		if (e_pos[0] < 0)
			rrb(b);
		else
			rb(b);
		i++;
	}
	// pa(a,b);
}

void	sort_action(int e_pos[][2], t_stack **a, t_stack **b)
{
	int		i;
	int		min;
	int		mvs;
	int		index;
	t_stack	*tmp;

	i = 1;
	tmp = *b;
	min = ft_abs(e_pos[0][0]) + ft_abs(e_pos[0][1]);
	index = 0;
	while(tmp)
	{
		mvs = ft_abs(e_pos[i][0]) + ft_abs(e_pos[i][1]);
		if (mvs < min)
		{
			min = mvs;
			index = i;
		}
		i++;
		tmp = tmp->next;
	}
	b_to_a(e_pos[index], a, b);
	// free(tmp);
}

int	locate(int *stack_arr, int x, t_stack **a)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		if ((x > stack_arr[i] && x < stack_arr[i + 1]) && (i <= ((*a)->size / 2)))
			return (i + 1);
		else if ((x > stack_arr[i] && x < stack_arr[i + 1]) && (i > ((*a)->size / 2)))
			return (i - (*a)->size + 1);
		i++;
		tmp = tmp->next;
	}
	if (x > stack_arr[0] && x < stack_arr[(*a)->size - 1])
		return (0);
	tmp = *a;
	while (tmp->x != (*a)->min)
	{
		i++;
		tmp = tmp->next;
	}
	// free(tmp);
	free(tmp);
	if (i > ((*a)->size / 2))
		return (i - (*a)->size + 1);
	return (i - 2);
	// return (-103);
}

void	a_indexing(int e_pos[][2], t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		*stack;
	int		i;
	int		k;

	i = 0;
	stack = malloc(((*a)->size + 1) * sizeof(int));
	// if (!stack)
	// 	errors ;
	tmp = *a;
	while(tmp)
	{
		stack[i++] = tmp->x;
		tmp = tmp->next;
	}
	i = 0;
	tmp = *b;
	while (tmp)
	{
		k = locate(stack, tmp->x, a);
		e_pos[i][0] = k;
		printf("%d\t(%d,%d)\n",tmp->x,e_pos[i][0],e_pos[i][1]);
		tmp = tmp->next;
		i++;
	}
	// sort_action(e_pos,a,b);
	// free(stack);
	// free(tmp);
}

void	b_indexing(int e_pos[][2], t_stack **b)
{
	t_stack *tmp;
	int		i;

	i = 0;
	tmp = *b;

	while (tmp)
	{
		if (i <= ((tmp->size / 2))){
			e_pos[i][1] = i;
			e_pos[i][0] = 0;
		}
		else{
			e_pos[i][1] = (tmp->size) * (-1) + i;
			e_pos[i][0] = 0;
		}
		i++;
		tmp = tmp->next;
	}
	// free(tmp);
}

void	sort(t_stack **a, t_stack **b)
{
	int		e_pos[(*b)->size + 1][2];

	b_indexing(e_pos, b);
	// (void)(*a);
	a_indexing(e_pos, a, b);
	b_indexing(e_pos, b);
	a_indexing(e_pos, a, b);
	// b_indexing(e_pos, b);
	// a_indexing(e_pos, a, b);
	// b_indexing(e_pos, b);
	// a_indexing(e_pos, a, b);
	// b_indexing(e_pos, b);
	// a_indexing(e_pos, a, b);
	// b_indexing(e_pos, b);
	// a_indexing(e_pos, a, b);
	// while (*b){
	// 	b_indexing(e_pos, b);
	// 	a_indexing(e_pos, a, b);
	// }
}
