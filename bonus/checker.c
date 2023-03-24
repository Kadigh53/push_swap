/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:12:23 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/03/23 22:23:58 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checking(t_stack **a, t_stack **b)
{
	char	*line;
	while (1)
	{
		line = get_next_line(0);
		if ()
	}
}

void	init_init(int *k,  int *l, t_stack **stack)
{
	int min;
	int max;
	int i;

	i = 0;
	min = k[0];
	max = k[0];
	while (i < *l)
	{
		if (k[i] < min)
			min = k[i];
		if (k[i] > max)
			max = k[i];
		i++;
	}
	(*stack)->min = min;
	(*stack)->max = max;
	(*stack)->next = NULL;
	// (*stack)->prev = NULL;
	(*stack)->size = 0;
	(*stack)->x = 0;
}

void	stack_init(int *k, t_stack **a, t_stack **b, int *l)
{
	int i;

	i = 0;
	*a = malloc(sizeof(t_stack));
	if (!*a)
		exit(1);
	*b = malloc(sizeof(t_stack));
	if (!*b)
		exit(1);
	init_init(k, l, a);
	init_init(k, l, b);
	while(i < *l)
	{
		push_el(a,k[*l - i - 1], (*a)->min, (*a)->max);
		i++;
	}
}

int main(int ac, char **av)
{
	t_stack *a;
	t_stack	*b;
	int l;
	int *k;

	k = parsing(ac, av, &l);
	if (!k)
		errors("Error\n");
	stack_init(k,&a,&b,&l);
	checking(&a,&b);
}
