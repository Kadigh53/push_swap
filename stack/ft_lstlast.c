/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 04:42:44 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/02 18:17:00 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

typedef struct s_stack
{
	int				x;
	int				size;
	struct s_stack	*next;
}	t_stack;

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
