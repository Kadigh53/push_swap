/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:56:13 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/08 01:09:49 by kadigh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void check_leaks() {
    pid_t pid = getpid();
    char cmd[256];
	sprintf(cmd, "leaks %d", pid);
    system(cmd);
}

int	main(int ac, char **av)
{
	t_vars	vars;
	int		l;

	if (ac < 2)
		exit(0);
	vars.k = parsing_f(ac, av, &l);
	if (!vars.k)
		exit(1);
	stack_init(vars.k, &vars.a, &vars.b, &l);
	if (l == 3)
		three_sort(&vars.a);
	else
	{
		f(&vars.a, &vars.b);
		sort(&vars.a, &vars.b);
	}
	free(vars.k);
	free_stack(&vars.a);
	free_stack(&vars.b);
	// atexit(check_leaks);
	return (0);
}
	// t_stack	*tmp ;
	// int i =0;
	// tmp = vars.a;
	// printf("\n===========\n\n");
	// i =0;
	// while (tmp)
	// {
	// 	if (i <= (vars.a->size)/2)
	// 		printf("a %d\t%d\t|| : max %d\n",i,tmp->x,tmp->max);
	// 	else
	// 		printf("a %d\t%d\t||\n",i - vars.a->size,tmp->x);
	// 	tmp = tmp->next;
	// 	i++;
	// }