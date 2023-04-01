/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:53:26 by kadigh            #+#    #+#             */
/*   Updated: 2023/04/01 19:37:47 by kadigh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	exec_instruct(t_stack **a, t_stack **b, char *instruct)
{
	if (ft_strncmp("pa\n", instruct, 3))
		pa(a, b);
	else if (ft_strncmp("pb\n", instruct, 3))
		pb(a, b);
	else if (ft_strncmp("sa\n", instruct, 3))
		sa(a, 1);
	else if (ft_strncmp("sb\n", instruct, 3))
		sb(b, 1);
	else if (ft_strncmp("ra\n", instruct, 3))
		ra(a, 1);
	else if (ft_strncmp("rb\n", instruct, 3))
		rb(b, 1);
	else if (ft_strncmp("rr\n", instruct, 3))
		rr(a, b);
	else if (ft_strncmp("rra\n", instruct, 4))
		rra(a, 1);
	else if (ft_strncmp("rrb\n", instruct, 4))
		rrb(b, 1);
	else if (ft_strncmp("rr\n", instruct, 4))
		rrr(a, b);
}

void    sort_check(t_stack **a, t_stack **b)
{
	char    str[2];
	char	*instruct
	int     n;

	n = 1;
	str[0] = '\0';
	str[1] = '\0';
	while(n)
	{
		while(str[0] != '\n')
		{
			n = read(0, str, 1);
			instruct = ft_strjoin(instruct, str);
		}
		exec_instruct(a, b, instruct);
	}
}