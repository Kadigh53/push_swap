/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kadigh <kadigh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:35:40 by kadigh            #+#    #+#             */
/*   Updated: 2023/03/31 15:43:11 by kadigh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS 
# define CHECKER_BONUS 

#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int x;
	int min;
	int max;
	int	size;
	struct s_stack  *next;
}  t_stack;

typedef struct s_vars
{
    t_stack *a;
    t_stack *b; 
} t_vars;

int	    *pars_check(int ac, char **av);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_split(char *s, char c, int *n);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(char *s);
int		ft_atoi(char *str);
void	errors(char *str);
# endif