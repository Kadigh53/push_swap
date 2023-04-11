/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:58:46 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/11 02:14:32 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	duplicate_check(int	*k, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
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
	while (i + 1 < *l)
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

void	split_free(char **p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
}

int	*pars_check(int ac, char **av, int *l)
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
	k = ft_malloc((*l) * sizeof(int));
	while (i < *l)
	{
		k[i] = ft_atoi(p[i]);
		i++;
	}
	if (*l == 1)
		exit(EXIT_SUCCESS);
	duplicate_check(k, *l);
	a_sorted(k, l);
	if (ac == 2)
		split_free(p);
	return (k);
}
