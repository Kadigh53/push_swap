/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:56:13 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/03/29 15:46:37 by kadigh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
	t_vars	vars;
	int		l;

	if (ac < 2)
		exit(0);
	vars.k = parsing_f(ac,av,&l);
	if (!vars.k)
		exit(1);
	stack_init(vars.k, &vars.a, &vars.b, &l);
	if (l == 3)
		three_sort(&vars.a);
	else
	{
		f(&vars.a,&vars.b);
		sort(&vars.a,&vars.b);
	}
	// t_stack	*tmp ;
	// int i =0;
	// tmp = vars.a;
	// printf("\n===========\n\n");
	// i =0;
	// while (tmp)
	// {
	// 	if (i <= (vars.a->size)/2)
	// 		printf("vars.a %d\t%d\t|| : max %d : size %d\n",i,tmp->x,tmp->max,tmp->size);
	// 	else
	// 		printf("vars.a %d\t%d\t|| : max %d : size %d\n",i - vars.a->size,tmp->x,tmp->max,tmp->size);
	// 	tmp = tmp->next;
	// 	i++;
	// }
}

// 78  { 78 89 100 300 400 500 600 900} 
// 89 
// 700 >
// 100 
// 300 
// 1000 >
// 400 
// 800 >
// 500 
// 600 
// 200 >
// 900 
// 88 >
// 565 >
// 321 >