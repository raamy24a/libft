/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 18:13:03 by radib             #+#    #+#             */
/*   Updated: 2025/04/17 14:28:21 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdlib.h>

int	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long long	total;

	i = 0;
	total = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		total *= 10;
		total += nptr[i] - '0';
		i++;
	}
	return (total * sign);
}
/*
int	main(void)
{
	printf("mon atoi : %d\n", ft_atoi("19223372036854775809"));
	printf("vrai atoi : %d\n", atoi("19223372036854775809"));
}
*/
