/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:58:46 by kadigh            #+#    #+#             */
/*   Updated: 2023/03/31 15:35:26 by kadigh           ###   ########.fr       */
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
		while(j < n)
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
	while(i < *l)
	{
		if (k[i] > k[i+1])
			break ;
		i++;
	}
	if ((i + 1) == *l)
	{
		ft_putstr_fd("Error\n",1);
		exit(0);
	}
}

int	*pars_check(int ac, char **av)
{
	int 	i;
	int		n;
	int		*k;
	char	**p;

	i = 0;
	if (ac == 2)
		p = ft_split(av[1], 32, &n);
	else
	{
		p = av + 1;
		n = ac - 1;
	}
	k = malloc((n + 1) * sizeof(int));
	if (!k)
		return (NULL);
	while (i < n)
	{
		k[i] = ft_atoi(p[i]);
		i++;
	}
	k[i] = 0;
	a_sorted(k, n);
	duplicate_check(k, n);
	return (k);
}