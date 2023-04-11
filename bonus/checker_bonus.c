/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <aaoutem-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:48:14 by aaoutem-          #+#    #+#             */
/*   Updated: 2023/04/10 22:00:34 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int ac, char **av)
{
	int		l;
	int		*k;
	t_vars	vars;

	
	if (ac < 2)
		exit(0);
	k = pars_check(ac, av, &l);
	stack_init(k, &vars.a, &vars.b, &l);
	sort_check(&vars.a, &vars.b);
}
