/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 10:06:16 by marvin            #+#    #+#             */
/*   Updated: 2025/11/17 10:06:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_in_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	start = 0;
	if (s1 == 0)
		return (NULL);
	if (set == 0)
		return (ft_strdup(s1));
	end = ft_strlen(s1) - 1;
	while (s1[start] != '\0' && is_in_set(s1[start], set))
		start++;
	while (end >= start && is_in_set(s1[end], set))
		end--;
	return (ft_substr(s1, start, end - start + 1));
}
/*
#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		char *result = ft_strtrim(argv[1], argv[2]);
		printf("Original: '%s'\n", argv[1]);
		printf("Set: '%s'\n", argv[2]);
		printf("Result: '%s'\n", result);
		free(result);
	}
	return (0);
}
*/