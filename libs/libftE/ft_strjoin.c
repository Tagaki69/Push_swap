/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:41:36 by elarue            #+#    #+#             */
/*   Updated: 2025/11/13 16:46:37 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		size;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	size = (int)ft_strlen(s1) + (int)ft_strlen(s2);
	dest = malloc(size + 1);
	if (dest == NULL)
		return (NULL);
	while (i < (int)ft_strlen(s1))
	{
		dest[i] = s1[i];
		i++;
	}
	while (i < size)
		dest[i++] = s2[j++];
	dest[i] = '\0';
	return (dest);
}
/*
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		char *result = ft_strjoin(argv[1], argv[2]);
		printf("%s\n", result);
		free(result);
	}
	return (0);
}
*/