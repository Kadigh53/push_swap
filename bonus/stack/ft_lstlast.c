/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 04:42:44 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/11 01:27:09 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"


t_stack	*ft_lstlast(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	if (!stack)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
