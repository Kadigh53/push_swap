/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 04:50:54 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/03/16 10:32:06 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack *ft_lstnew(int data, int min, int max)
{
    t_stack *node;

    node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->x = data;
    node->min = min;
    node->max = max;
    node->prev = NULL;
    node->next = NULL;
    return (node);
}
