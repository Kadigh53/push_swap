/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:56:54 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/04 00:58:11 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	duplicate_check(int	*k, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (k[i] == k[j])
				errors("Error\n");
			j++;
		}
		i++;
	}
}

void	a_sorted(int *k, int *l)
{
	int	i;

	i = 0;
	while (i < *l)
	{
		if (k[i] > k[i + 1])
			break ;
		i++;
	}
	if ((i + 1) == *l)
	{
		exit(0);
	}
}

int	*parsing_f(int ac, char **av, int *l)
{
	int		i;
	int		*k;
	char	**p;

	i = 0;
	if (ac == 2)
		p = ft_split(av[1], 32, l);
	else
	{
		p = av + 1;
		*l = ac - 1;
	}
	k = ft_malloc((*l + 1) * sizeof(int));
	while (i < *l)
	{
		k[i] = ft_atoi(p[i]);
		i++;
	}
	if (*l == 1)
		exit(EXIT_SUCCESS);
	k[i] = 0;
	a_sorted(k, l);
	duplicate_check(k, *l);
	return (k);
}
