/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 04:50:15 by kadigh            #+#    #+#             */
/*   Updated: 2023/04/08 04:50:46 by kadigh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	*ft_malloc(int size)
{
	void	*buff;

	buff = malloc(size);
	if (!buff)
		errors("Malloc failed");
	return (buff);
}
