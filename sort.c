/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 02:27:28 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/11 03:27:20 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	locate(int x, t_stack **a)
{
	int		i;
	t_stack	*tm;

	i = 0;
	tm = *a;
	while (tm->next)
	{
		if (is_between(tm->x, (tm->next)->x, x) && (i <= ((*a)->size / 2)))
			return (i + 1);
		else if (is_between(tm->x, (tm->next)->x, x) && (i > ((*a)->size / 2)))
			return (i - (*a)->size + 1);
		i++;
		tm = tm->next;
	}
	tm = *a;
	while (tm->next)
		tm = tm->next;
	if (is_between(tm->x, (*a)->x, x))
		return (0);
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

void	indexin(t_stack **a, t_stack **b)
{
	int		(*e_pos)[2];

	e_pos = NULL;
	while ((*b)->next)
	{
		e_pos = malloc(((*b)->size) * sizeof(int [2]));
		if (!e_pos)
			exit(EXIT_FAILURE);
		b_indexing(e_pos, b);
		a_indexing(e_pos, a, b);
		free(e_pos);
	}
	e_pos = malloc(((*b)->size) * sizeof(int [2]));
	if (!e_pos)
		exit(EXIT_FAILURE);
	b_indexing(e_pos, b);
	a_indexing(e_pos, a, b);
	free(e_pos);
}

void	sort(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		i;

	if (*b)
		indexin(a, b);
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
