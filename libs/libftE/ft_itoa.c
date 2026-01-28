/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:43:10 by marvin            #+#    #+#             */
/*   Updated: 2025/11/14 10:43:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_num(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count = 1;
		n = n * -1;
	}
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		count;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	count = count_num(n);
	dest = malloc(count * sizeof(char) + 1);
	if (dest == NULL)
		return (NULL);
	dest[count] = '\0';
	count--;
	if (n < 0)
	{
		dest[0] = '-';
		n = n * -1;
	}
	while (n != 0)
	{
		dest[count--] = (n % 10) + '0';
		n = n / 10;
	}
	return (dest);
}
/*
#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *result = ft_itoa(atoi(argv[1]));
		printf("%s\n", result);
		free(result);
	}
	return (0);
}
*/