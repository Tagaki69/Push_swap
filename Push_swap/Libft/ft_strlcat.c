/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:56:32 by elarue            #+#    #+#             */
/*   Updated: 2025/11/05 17:05:28 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	size_src;
	size_t	size_dst;

	i = -1;
	size_src = 0;
	size_dst = 0;
	while (src[size_src] != '\0')
		size_src++;
	if (size == 0)
		return (size_src);
	while (dst[size_dst] != '\0')
		size_dst++;
	if (size <= size_dst)
		return (size + size_src);
	while (src[++i] != '\0' && size_dst + i + 1 < size)
		dst[size_dst + i] = src[i];
	dst[size_dst + i] = '\0';
	return (size_dst + size_src);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		printf("%ld", ft_strlcat(argv[1], argv[2], atoi(argv[3])));
	}
	return (0);
}
*/
