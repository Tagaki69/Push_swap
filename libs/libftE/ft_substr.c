/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:09:35 by elarue            #+#    #+#             */
/*   Updated: 2025/11/13 15:35:37 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dest;
	size_t	size;

	i = 0;
	if (s == 0)
		return (NULL);
	size = ft_strlen(s);
	if (len == 0 || start >= size)
	{
		dest = malloc(1);
		if (dest == NULL)
			return (NULL);
		dest[0] = '\0';
		return (dest);
	}
	if (len > size - start)
		len = size - start;
	dest = malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	while (i < len && start < size)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*dest;

	if (argc == 4)
	{
		dest = ft_substr(argv[1], atoi(argv[2]), atoi(argv[3]));
		printf("%s", dest);
	}
	return (0);
}
*/