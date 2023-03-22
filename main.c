/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:56:13 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/03/22 13:24:13 by aaoutem-         ###   ########.fr       */
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
	int i=0;
	t_stack *tmp = a;
	// while (tmp)
	// {
	// 	printf("a %d %d\t|| : min %d : max %d : size %d\n",i,tmp->x,tmp->min,tmp->max,tmp->size);
	// 	i++;
	// 	tmp = tmp->next;
	// }
	f(&a,&b);
	// tmp = a;
	// while (tmp)
	// {
	// 	printf("a %d %d\t|| : min %d : max %d : size %d\n",i,tmp->x,tmp->min,tmp->max,tmp->size);
	// 	i++;
	// 	tmp = tmp->next;
	// }
	// tmp = b;
	// printf("\n===========\n\n");
	// while (tmp)
	// {
	// 	printf("b  %d\t|| : min %d : max %d : size %d\n",tmp->x,tmp->min,tmp->max,tmp->size);
	// 	tmp = tmp->next;
	// }
	// printf("\n");
	sort(&a,&b);

	// tmp = a;	
	// while (tmp)
	// {
	// 	printf("a  %d\t|| : min %d : max %d : size %d\n",tmp->x,tmp->min,tmp->max,tmp->size);
	// 	tmp = tmp->next;
	// }
	// printf("\n===========\n\n");
	// tmp = b;
	// while (tmp)
	// {
	// 	printf("a  %d\t|| : min %d : max %d : size %d\n",tmp->x,tmp->min,tmp->max,tmp->size);
	// 	tmp = tmp->next;
	// }
	i = 0;
	tmp = a;
	while(tmp->x != tmp->min){
		i++;
		tmp = tmp->next;
	}
	while (a->x != a->min)
	{
		if (i > (a->size) / 2)
			rra(&a, 1);
		else
			ra(&a, 1);
	}
	tmp = a;
	// printf("\n===========\n\n");
	// i =0;
	// while (tmp)
	// {
	// 	if (i <= (a->size)/2)
	// 		printf("a %d\t%d\t|| : max %d : size %d\n",i,tmp->x,tmp->max,tmp->size);
	// 	else
	// 		printf("a %d\t%d\t|| : max %d : size %d\n",i - a->size,tmp->x,tmp->max,tmp->size);
	// 	tmp = tmp->next;
	// 	i++;
	// }
	// i = 0;
	// tmp = b;
	// printf("\n===========\n\n");
	// while (tmp)
	// {
	// 	printf("b  %d\t%d\t|| : min %d : size %d max : %d \n",i,tmp->x,tmp->min,tmp->size,tmp->max);
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