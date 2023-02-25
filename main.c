/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:56:13 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/25 00:47:17 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void ra(t_stack **a)
// {
// 	t_stack *first;
// 	t_stack *last;

//     // if (*a == NULL || (*a)->next == NULL) {
//     //     // The stack is empty or has only one element, no rotation possible
//     //     return;
//     // }
//     first = (*a)->next;
//     last = first;
//     while ((last->next) != NULL) {
//         last = last->next;
//     }
// 	(*a)->next = NULL;
//     last->next = *a;
//     *a = first;
// }

int main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_stack	*tmp;
	t_stack	*tmp1;
	int	*k;
	int	l;

	if (ac < 2)
		exit(0);
	k = parsing_f(ac,av,&l);
	if (!k)
		exit(1);
	
	stack_init(k, &a, &b, &l);
	tmp = a;
	tmp1 = b;
	while(tmp)
	{
		printf("A  %d | size:%d\n",tmp->x,(tmp->size));
		tmp = tmp->next;
	}
	// ra(&a);
	// tmp = a;
	// printf("\n===========\n\n");
	// while(tmp)
	// {
	// 	printf("A  %d | size:%d\n",tmp->x,(tmp->size));
	// 	tmp = tmp->next;
	// }
	// if (!tmp->next)
	// 	printf("\n%d",tmp->x);
	
	write(1,"\n",1);
	printf(" ------------ \n\n");
	while(tmp1)
	{
		printf("B  %d | size:%d\n",tmp1->x,(tmp1->size));
		tmp1 = tmp1->next;
	}	
	// rr(&a,&b);
	// printf("\n +++++++++ \n\n +++++++++\n");
	// tmp =a;
	// while(tmp)
	// {
	// 	printf("A  %d | size:%d\n",tmp->x,(tmp->size));
	// 	tmp = tmp->next;
	// }
	// printf("\n ------------ \n\n");
	// tmp1 =b;
	// while(tmp1)
	// {
	// 	printf("B  %d | size:%d\n",tmp1->x,(tmp1->size));
	// 	tmp1 = tmp1->next;
	// }
	// if (!tmp->next)
	// 	printf("\n\nnext:Orghid yat");
	// printf("\n\nsize:%d", tmp->size);
	// printf("\n\ndata:%d", tmp->x);
}
