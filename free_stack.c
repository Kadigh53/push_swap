/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:58:33 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/04 21:29:36 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    free_stack(t_stack **stack, t_stack **a)
{
    while (!(*stack)->next && !(*stack)->size){
        printf("ff");
        pop_el(stack);
    }
    free(*stack);
}