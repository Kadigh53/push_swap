/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 01:21:34 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/22 02:28:11 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void errors(int x)
// {
// 	if (x == 0)
// 		write(2,"\033[1;31mERROR:invalid argument\n",33);
// 	exit(1);
// }
void errors(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}