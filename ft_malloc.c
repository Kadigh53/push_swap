/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 03:40:43 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/11 03:41:19 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_malloc(int size)
{
	void	*buff;

	buff = malloc(size);
	if (!buff)
		errors("Malloc failed");
	return (buff);
}
