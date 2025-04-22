/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:15:57 by radib             #+#    #+#             */
/*   Updated: 2025/04/18 15:58:06 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_strjoin;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	str_strjoin = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str_strjoin)
		return (NULL);
	while (s1[i])
	{
		str_strjoin[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str_strjoin[i] = s2[j];
		i++;
		j++;
	}
	str_strjoin[i] = '\0';
	return (str_strjoin);
}

// int	main(void)
// {
// 	printf("%s\n", ft_strjoin("tripouille", "42 "));
// }
