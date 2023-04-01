/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaoutem- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:14:49 by aaoutem-          #+#    #+#             */
/*   Updated: 2022/10/16 23:10:52 by aaoutem-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (!n)
		return (0);
	while (n-- > 0)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		if (p1[i] == '\0' && p2[i] == '\0')
			return (0);
		i++;
	}
	return (0);
}
