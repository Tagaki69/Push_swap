/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:45:12 by elarue            #+#    #+#             */
/*   Updated: 2025/11/12 14:40:11 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <limits.h>

long	ft_atoi(const char *nptr)
{
	size_t	i;
	long	s;
	long	n;

	i = 0;
	s = 1;
	n = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			s = -1;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (n > ((long)2147483647 - (nptr[i] - '0')) / 10)
		{
			if (s == 1)
				return ((long)2147483647 + 1);
			return ((long)-2147483647 - 1);
		}
		n = n * 10 + (nptr[i] - '0');
		i++;
	}
	return (n * s);
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		printf("%ld\n", ft_atoi(argv[1]));
	}
	return (0);
}
*/