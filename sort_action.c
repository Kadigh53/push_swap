/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 14:03:18 by aaoutem-            #+#    #+#             */
/*   Updated: 2023/03/29 14:04:45 by aaoutem-           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int a)
{
	if (a < 0)
		a = a * (-1);
	return (a);
}

int	is_between(int *stack, int start, int next, int x)
{
	if (stack[start] < x && x < stack[next])
		return (1);
	else
		return (0);
}

void	rotate(int r_nbr, int e_pos, t_stack **stack)
{
	int	i;

	i = 0;
	while (i < r_nbr)
	{
		if (e_pos < 0) 
			rra(stack, 1);
		else if (e_pos > 0)
			ra(stack, 1);
		i++;
	}
}

void	b_to_a(int e_pos[2], t_stack **a, t_stack **b)
{
	// int rot_a;
	// int	rot_b;
	// int	i;
	int	k;
	int mr;

	// printf("[%d,%d]",e_pos[0],e_pos[1]);
	// rot_a = ft_abs(e_pos[0]);
	// rot_b = ft_abs(e_pos[1]);
	// i = 0;
	mr = 0;
	k = 0;
	if ((e_pos[1] * e_pos[0]) > 0){
		mr = ft_min(ft_abs(e_pos[0]), ft_abs(e_pos[1]));
		k = ft_min(ft_abs(e_pos[0]), ft_abs(e_pos[1]));
	}
	while (mr)
	{
		if ((e_pos[0] > 0) && (e_pos[1] > 0))
			rr(a, b);
		else
			rrr(a,b);
		mr--;
	}
	// mr = k;
	// while (i < rot_a - mr)
	// {
	// 	if (e_pos[0] < 0) 
	// 		rra(a, 1);
	// 	else if (e_pos[0] > 0)
	// 		ra(a, 1);
	// 	i++;
	// }
	// i = 0;
	// while (i < rot_b - mr)
	// {
	// 	if (e_pos[1] < 0)
	// 		rrb(b, 1);
	// 	else if (e_pos[1] > 0)
	// 		rb(b, 1);
	// 	i++;
	// }
	rotate(ft_abs(e_pos[0]) - k, e_pos[0], a);
	rotate(ft_abs(e_pos[1]) - k, e_pos[1], b);
	pa(a,b);
}

void	sort_action(int e_pos[][2], t_stack **a, t_stack **b)
{
	int		i;
	int		min;
	int		mvs;
	int		index;
	t_stack	*tmp;

	i = 0;
	tmp = *b;
	min = ft_abs(e_pos[0][0]) + ft_abs(e_pos[0][1]);
	index = 0;
	while(tmp->next)
	{
		tmp = tmp->next;
		i++;
		mvs = ft_abs(e_pos[i][0]) + ft_abs(e_pos[i][1]);
		if (mvs < min && i <= ((*b)->size / 2))
		{
			min = mvs;
			index = i;
		}
		else if (mvs <= min && i > ((*b)->size / 2))
		{
			min = mvs;
			index = i;
		}
	}
	mvs = ft_abs(e_pos[i][0]) + ft_abs(e_pos[i][1]);
	if (mvs <= min)
		index = i;
	b_to_a(e_pos[index], a, b);
}