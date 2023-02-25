/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 04:50:54 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/24 00:45:05 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack *ft_lstnew(int data)
{
    t_stack *node;

    node = (t_stack *)malloc(sizeof(t_stack));
    if (!node)
        return (NULL);
    node->x = data;
    node->next = NULL;
    return (node);
}
