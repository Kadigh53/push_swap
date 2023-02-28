/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:56:13 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/28 01:00:07 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int	*k;
	int	l;

	if (ac < 2)
		exit(0);
	k = parsing_f(ac,av,&l);
	if (!k)
		exit(1);
	stack_init(k, &a, &b, &l);
	t_stack *tmp = a;
	while (tmp)
	{
		printf("a  %d\t|| : min %d : max %d : size %d\n",tmp->x,tmp->min,tmp->max,tmp->size);
		tmp = tmp->next;
	}
	f(&a);
	tmp = a;
	printf("\n===========\n\n");
	while (tmp)
	{
		printf("a  %d\t|| : min %d : max %d : size %d\n",tmp->x,tmp->min,tmp->max,tmp->size);
		tmp = tmp->next;
	}
	
	// pb
	// pb
	// pb
	// pb
	// ...
}
