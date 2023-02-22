/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:57:15 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/02/22 04:21:23 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

void    *parsing_f(int ac, char **av);

char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char *s, char c, int *n);
size_t	ft_strlen(char *s);
int     ft_atoi(char *str);
void    errors(char *str);


#endif