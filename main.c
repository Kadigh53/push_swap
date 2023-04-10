/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:56:13 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/10 06:19:25 by aaoutem-         ###   ########.fr       */
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
	// atexit(check_leaks);
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
		f(&vars.a, &vars.b, &vars);
		sort(&vars.a, &vars.b);
	}
	// t_stack	*tmp ;
	// int i =0;
	// tmp = vars.a;
	// printf("\n===========\n\n");
	// i =0;
	// while (tmp)
	// {
	// 	printf("a \t%d\t|| : max %d|| : min %d|| : size %d\n",tmp->x,tmp->max,tmp->min,tmp->size);
	// 	tmp = tmp->next;
	// 	i++;
	// }
	free_mem(&vars);
	return (0);
}
