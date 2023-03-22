/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 02:27:28 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/03/22 13:22:13 by aaoutem-         ###   ########.fr       */
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

int	is_between(int *stack, int start, int next, int x)
{
	if (stack[start] < x && x < stack[next])
		return (1);
	else
		return (0);
}

void	b_to_a(int e_pos[2], t_stack **a, t_stack **b)
{
	int	i;
	int rot_a;
	int	rot_b;
	int	k;
	int mr;

	i = 0;
	mr = 0;
	k = 0;
	// printf("[%d,%d]",e_pos[0],e_pos[1]);
	rot_a = ft_abs(e_pos[0]);
	rot_b = ft_abs(e_pos[1]);
	if ((e_pos[1] * e_pos[0]) > 0){
		mr = ft_min(rot_a, rot_b);
		k = ft_min(rot_a, rot_b);
	}
	while (mr)
	{
		if ((e_pos[0] > 0) && (e_pos[1] > 0))
			rr(a, b);
		else
			rrr(a,b);
		mr--;
	}
	// mr = ft_min(rot_a, rot_b);
	mr = k;
	while (i < rot_a - mr)
	{
		if (e_pos[0] < 0) 
			rra(a, 1);
		else if (e_pos[0] > 0)
			ra(a, 1);
		i++;
	}
	i = 0;
	while (i < rot_b - mr)
	{
		if (e_pos[1] < 0)
			rrb(b, 1);
		else if (e_pos[1] > 0)
			rb(b, 1);
		i++;
	}
	// printf("  %d\n",(*b)->x);
	// printf("\n");
	// i =0;
	// t_stack *tmp = *b;
	// while (tmp)
	// {
	// 	printf("a %d %d  \t\t size \n",tmp->x,tmp->size);
	// 	tmp = tmp->next;
	// }
	// printf("\n");
	// tmp = *a;
	// while (tmp)
	// {
	// 	printf("a %d %d  \t\t size %d\n",i,tmp->x,tmp->size);
	// 	tmp = tmp->next;
	// }
	// printf("\n");
	pa(a,b);
}
// void	sort_action(int e_pos[][2], t_stack **a, t_stack **b)
// {
// 	int	i;

// 	while (i <= ((*b)->size / 2))
// 	{}
// }

void	sort_action(int e_pos[][2], t_stack **a, t_stack **b)
{
	int		i;
	int		min;
	// int		a_mov;
	// int		b_mov;
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
		// a_mov = e_pos[i][0];
		// b_mov = e_pos[i][1];
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
	// printf("i : %d    index : %d size(b):%d\n",i,index,(*b)->size);
	b_to_a(e_pos[index], a, b);
}

int	locate(int *stack_arr, int x, t_stack **a)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		if (is_between(stack_arr, i, i + 1, x) && (i <= ((*a)->size / 2)))
			return (i + 1);
		else if (is_between(stack_arr, i, i + 1, x) && (i > ((*a)->size / 2)))
			return (i - (*a)->size + 1);
		i++;
		tmp = tmp->next;
	}
	if (is_between(stack_arr, (*a)->size - 1, 0, x))
		return (0);
	tmp = *a;
	i = 0;
	while (tmp)
	{
		if ((tmp->x == (*a)->min) && i <= ((*a)->size / 2))
			return (i);
		else if ((tmp->x == (*a)->min) && i > ((*a)->size / 2))
			return (i - (*a)->size + 1);
		i++;
		tmp = tmp->next;
	}
	return((*a)->size);
	// return (13);
}

void	a_indexing(int e_pos[][2], t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		*stack;
	int		i;

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
		e_pos[i][0] = locate(stack, tmp->x, a);
		tmp = tmp->next;
		i++;
	}
	tmp = *b;
	i =0;
	while (tmp)
	{
		// printf(" %d [%d,%d]\n",tmp->x,e_pos[i][0],e_pos[i][1]);
		i++;
		tmp = tmp->next;
	}
	// printf("\n");
	sort_action(e_pos,a,b);
	free(stack);
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
		if (i <= ((tmp->size / 2)))
			e_pos[i][1] = i;
		else
			e_pos[i][1] = (tmp->size) * (-1) + i;
		i++;
		tmp = tmp->next;
	}
	// free(tmp);
}

void	sort(t_stack **a, t_stack **b)
{
	int		e_pos[(*b)->size + 1][2];

	while ((*b)->next && (*b)->size){
		b_indexing(e_pos, b);
		a_indexing(e_pos, a, b);
	}
	b_indexing(e_pos, b);
	a_indexing(e_pos, a, b);
}
