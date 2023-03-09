/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 02:27:28 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/03/09 11:26:46 by aaoutem-         ###   ########.fr       */
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
	// printf("stack[i]:%d\tx:%d\tstack[i+1]:%d\n",stack[i],x,stack[i+1]);
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
	int mr;

	i = 0;
	mr = 0;
	printf("[%d,%d]\n",e_pos[0],e_pos[1]);
	rot_a = ft_abs(e_pos[0]);
	rot_b = ft_abs(e_pos[1]);
	// printf("{\nrot_a : %d\nrot_b : %d\n",rot_a,rot_b);
	if ((e_pos[1] * e_pos[0]) > 0){
		mr = ft_min(rot_a, rot_b);
		// printf("    mr : %d | rot_a:%d rot_b:%d",mr,rot_a,rot_b);	
	}
	while (mr)
	{
		if ((e_pos[0] > 0) && (e_pos[1] > 0))
			rr(a, b);
		else
			rrr(a,b);
		mr--;
		if (!mr)
		{
			mr = ft_min(rot_a, rot_b);
			break ;
		}
	}
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
	// printf("}\n");
	pa(a,b);
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
	while(tmp->next)
	{
		mvs = ft_abs(e_pos[i][0]) + ft_abs(e_pos[i][1]);
		if (mvs < min)
		{
			min = mvs;
			index = i;
		}
		// if (mvs <= min && i > ((*a)->size / 2)) Must to check this case where the updates of the minimums whith the same complexity
		// {
		// 	min = mvs;
		// 	index = i;
		// }
		// else if (mvs < min && i <= ((*a)->size / 2))
		// {
		// 	min = mvs;
		// 	index = i;
		// }
		i++;
		tmp = tmp->next;
	}
	// printf("index: %d\n[%d,%d]\n",index, e_pos[index][0],e_pos[index][1]);
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
		if (is_between(stack_arr, i, i + 1, x) && (i <= ((*a)->size / 2)))
			return (i + 1);
		else if (is_between(stack_arr, i, i + 1, x) && (i > ((*a)->size / 2)))
			return (i - (*a)->size + 1);
		i++;
		tmp = tmp->next;
	}
	if (is_between(stack_arr, (*a)->size - 1, 0, x)){
		printf("her > ");
		return (0);
	}
	tmp = *a;
	i = 0;
	while (tmp) //tmp->x != (*a)->min)
	{
		// printf("\n\nam here\n");
		if ((tmp->x == (*a)->min) && i <= ((*a)->size / 2)){
			printf("fh ");
			return (i);
		}
		else if ((tmp->x == (*a)->min) && i > ((*a)->size / 2))
			return (i - (*a)->size + 1);
		i++;
		tmp = tmp->next;
	}
	// if (i <= ((*a)->size / 2)){
	// 	printf("her2 > ");
	// 	return (i - 1);
	// }
	// printf("h %d er3 > ",i);
	// return (i - (*a)->size + 1);
	return (13);
}

void	a_indexing(int e_pos[][2], t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		*stack;
	int		i;
	// int		k;

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
		// e_pos[i][0] = k;
		printf("%d\t(%d,%d)\n",tmp->x,e_pos[i][0],e_pos[i][1]);
		tmp = tmp->next;
		i++;
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
		if (i <= ((tmp->size / 2))){
			e_pos[i][1] = i;
			// e_pos[i][0] = 0;
		}
		else{
			e_pos[i][1] = (tmp->size) * (-1) + i;
			// e_pos[i][0] = 0;
		}
		i++;
		tmp = tmp->next;
	}
	// free(tmp);
}

void	sort(t_stack **a, t_stack **b)
{
	int		e_pos[(*b)->size + 1][2];
	// int		**e_pos;
	// e_pos = molloc(((*b)->size + 1) * sizeof(int *));

	// b_indexing(e_pos, b);
	// a_indexing(e_pos, a, b);
	// b_indexing(e_pos, b);
	// a_indexing(e_pos, a, b);
	// b_indexing(e_pos, b);
	// a_indexing(e_pos, a, b);
	while ((*b)->next){
		b_indexing(e_pos, b);
		a_indexing(e_pos, a, b);
	}
}
