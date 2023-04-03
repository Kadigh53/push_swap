/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:09:01 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/03 20:52:57 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

static int	valid_nbr(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		errors("Error\n");
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		errors("Error\n");
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			errors("Error\n");
		i++;
	}
	return (1);
}

static int	is_space(char *str)
{
	int	i;

	i = 0;
	while (((str[i] > 8 && str[i] < 14) || (str[i] == 32)) && str[i] != 0)
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	valid_nbr(str);
	i = is_space(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
		result = result * 10 + (str[i++] - 48);
	result = result * sign;
	if (result > INT32_MAX || result < INT32_MIN)
		errors("Error\n");
	return (result);
}
