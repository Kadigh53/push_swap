/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:12:28 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/03/23 22:24:24 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include <unistd.h>
#include <stdlib.h>

#define pa 1
#define pa 1


typedef struct s_stack
{
	int x;
	int min;
	int max;
	int	size;
	struct s_stack  *next;
}	t_stack;

int *parsing(int ac, char **av, int *l);
#endif