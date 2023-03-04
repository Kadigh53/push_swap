/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 02:27:28 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/03/04 02:34:33 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_action(int epos[][2],t_stack **a,t_stack **b)
{}

int	locate(int *stack_arr, int x, t_stack **a)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		if ((x > stack_arr[i] && x < stack_arr[i + 1]) && i <= ((*a)->size / 2))
			return (i + 1);
		else if ((x > stack_arr[i] && x < stack_arr[i + 1]) && i > ((*a)->size / 2))
			return (i - (*a)->size);
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
	if (i > ((*a)->size / 2))
		return (i - (*a)->size + 1);
	return (i - 2);
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
	sort_action(e_pos,a,b);
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
	free(tmp);
}

void	sort(t_stack **a, t_stack **b)
{
	int		e_pos[(*b)->size + 1][2];

	b_indexing(e_pos, b);
	a_indexing(e_pos, a, b);
	// while (*b){
	// 	b_indexing(e_pos, b);
	// 	a_indexing(e_pos, a, b);
	// }
}
