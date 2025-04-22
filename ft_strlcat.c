/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radib <radib@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:14:54 by radib             #+#    #+#             */
/*   Updated: 2025/04/18 11:30:49 by radib            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	if (size == 0)
		return (ft_strlen(src) + size);
	if (size <= i)
		return (size + ft_strlen(src));
	while (i + j + 1 < size && src[j])
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char	src[8] = "bonjour";
// 	char		dst[14] = "fooo";

// 	printf("mwaaa: %ld\n", ft_strlcat(dst, src, 0));
// 	printf("%s\n", dst);
// }
