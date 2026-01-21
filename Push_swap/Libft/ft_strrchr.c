/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 09:58:20 by elarue            #+#    #+#             */
/*   Updated: 2025/11/12 11:56:35 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	if (i == 0)
		return ((char *)&s[i]);
	return (0);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	char	*result;
	int		c;

	if (argc == 3)
	{
		c = (char)argv[2][0];
		result = ft_strrchr(argv[1], c);
		if (result != 0)
			printf("Character found: %s\n", result);
		else
			printf("Character not found\n");
	}
	return (0);
}
*/