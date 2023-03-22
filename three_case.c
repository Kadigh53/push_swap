/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 21:53:21 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/03/22 22:23:31 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    three_sort(t_stack **a, t_stack **b)
{
	int first;
	int mid;
	int last;
	
	first = (*a)->x;
	mid = ((*a)->next)->x;
	last = (((*a)->next)->next)->x;
	if (first < mid && mid > last)
	{
		ra(a, 1);
		sa(a, 1);
		rra(a, 1);
	}
	if ()
}