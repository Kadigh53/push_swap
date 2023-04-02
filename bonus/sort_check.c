/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 17:53:26 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/02 02:05:52 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_a_sorted(t_stack **a);
{
	t_stack *tmp;
	
	tmp = *a;
	while(tmp)
	{
		
	}
}

void	exec_instruct(t_stack **a, t_stack **b, char *instruct)
{
	if (!instruct)
		return ;
	if (!ft_strncmp("pa\n", instruct, 3))
		pa(a, b);
	else if (!ft_strncmp("pb\n", instruct, 3))
		pb(a, b);
	else if (!ft_strncmp("sa\n", instruct, 3))
		sa(a);
	else if (!ft_strncmp("sb\n", instruct, 3))
		sb(b);
	else if (!ft_strncmp("ra\n", instruct, 3))
		ra(a);
	else if (!ft_strncmp("rb\n", instruct, 3))
		rb(b);
	else if (!ft_strncmp("rr\n", instruct, 3))
		rr(a, b);
	else if (!ft_strncmp("rra\n", instruct, 4))
		rra(a);
	else if (!ft_strncmp("rrb\n", instruct, 4))
		rrb(b);
	else if (!ft_strncmp("rrr\n", instruct, 4))
		rrr(a, b);
}

void    sort_check(t_stack **a, t_stack **b)
{
	char	*instruct;
	t_stack *tmp;
	int     n;

	n = 1;
	instruct = (void *)1;
	while(instruct)
	{
		instruct = get_next_line(0);
		exec_instruct(a, b, instruct);
	}
	is_a_sorted(a);
}