/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:56:54 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/03/23 22:18:38 by aaoutem-         ###   ########.fr       */
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
				errors("\033[1;31mERROR:duplicate arguments\n");
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
		ft_putstr_fd("\033[1;31mAlready sorted\n",1);
		exit(0);
	}
}

int	*parsing_f(int ac, char **av, int *l)
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
	*l = n;
	k = malloc((n + 1) * sizeof(int));
	if (!k)
		return (NULL);
	while (i < n)
	{
		k[i] = ft_atoi(p[i]);
		i++;
	}
	k[i] = 0;
	a_sorted(k, l);
	duplicate_check(k, n);
	return (k);
}

// int main(int ac, char **av)
// {
// 	int *k = parsing_f(ac, av);
// 	int i = 0;
// 	if (ac < 2)
// 		errors("\033[1;31mERROR:invalid argument\n");
// 	// while (i < ac -1)
// 	// 	printf("%d\n", k[i++]);
// 	printf("%d\n", k[i++]);
// 	printf("%d\n", k[i++]);
// 	printf("%d\n", k[i++]);
// 	printf("%d\n", k[i++]);
// 	printf("%d\n", k[i++]);
// 	printf("%d\n", k[i++]);
// 	printf("%d\n", k[i++]);
// 	printf("%d\n", k[i++]);
// 	printf("%d\n", k[i++]);
// }
