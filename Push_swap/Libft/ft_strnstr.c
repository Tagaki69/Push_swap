/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 10:14:59 by elarue            #+#    #+#             */
/*   Updated: 2025/11/12 11:09:19 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!big && len == 0)
		return (NULL);
	if (little[j] == '\0')
		return ((char *)&big[i]);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while ((i + j) < len && big[i + j] == little[j])
		{
			j++;
			if (little[j] == '\0')
			{
				return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		printf("%s", ft_strnstr(argv[1], argv[2], atoi(argv[3])));
	}
	return (0);
}
*/
