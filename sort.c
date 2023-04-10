/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 02:27:28 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/10 05:36:52 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	locate_damax(t_stack **a)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *a;
	while (tmp)
	{
		if ((tmp->x == (*a)->min) && i <= ((*a)->size / 2))
			return (i);
		else if ((tmp->x == (*a)->min) && i > ((*a)->size / 2))
			return (i - (*a)->size);
		i++;
		tmp = tmp->next;
	}
	// printf("mn hna lMAX");
	return ((*a)->size);
}



int	locate(int x, t_stack **a)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *a;
	while (tmp->next)
	{
		// printf("i : %d    ",i);
		if (is_between(tmp->x, (tmp->next)->x, x) && (i <= ((*a)->size / 2)))
		{
			// printf("1 %d\n", (*a)->size);
			return (i + 1);
		}
		else if (is_between(tmp->x, (tmp->next)->x, x) && (i > ((*a)->size / 2)))
		{
			// printf("2 dif:%d (i : %d)size:%d strt:%d (x:%d) nxt:%d\n", i - (*a)->size + 1,i,(*a)->size,stack_arr[i],x,stack_arr[i+1]);
			return (i - (*a)->size + 1);
		}
		i++;
		tmp = tmp->next;
	}
	tmp = *a;
	while (tmp->next)
	{
		// printf("%d\n",tmp->x);
		tmp = tmp->next;
	}
	if (is_between(tmp->x, (*a)->x, x))
	{
		// printf("hy ghid");
		return (0);
	}
	return (locate_damax(a));
}

void	a_indexing(int e_pos[][2], t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *b;
	while (tmp)
	{
		e_pos[i][0] = locate(tmp->x, a);
		// printf(" \t%d\t[%d,%d]\n",tmp->x,e_pos[i][0],e_pos[i][1]);
		tmp = tmp->next;
		i++;
	}
	sort_action(e_pos, a, b);
}

void	b_indexing(int e_pos[][2], t_stack **b)
{
	t_stack	*tmp;
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
}

void	r(t_stack **a, t_stack **b)
{
	int		e_pos[(*b)->size + 1][2];

	while ((*b)->next)
	{
		b_indexing(e_pos, b);
		a_indexing(e_pos, a, b);
	}
	b_indexing(e_pos, b);
	a_indexing(e_pos, a, b);
}

void	sort(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	if (*b)
		r(a, b);
	tmp = *a;
	i = 0;
	while (tmp->x != tmp->min)
	{
		i++;
		tmp = tmp->next;
	}
	while ((*a)->x != (*a)->min)
	{
		if (i > ((*a)->size) / 2)
			rra(a, 1);
		else
			ra(a, 1);
	}
}
