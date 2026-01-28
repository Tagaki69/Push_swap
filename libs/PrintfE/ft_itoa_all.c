/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:08:44 by elarue            #+#    #+#             */
/*   Updated: 2025/11/27 13:08:44 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	uitoa_count_num(unsigned long n, int base)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		count++;
		n = n / base;
	}
	return (count);
}

char	*ft_uitoa_base(unsigned long n, int base, char *charset)
{
	char			*dest;
	unsigned int	count;

	if (n == 0)
		return (ft_strdup("0"));
	count = uitoa_count_num(n, base);
	dest = malloc(count * sizeof(char) + 1);
	if (dest == NULL)
		return (NULL);
	dest[count] = '\0';
	count--;
	while (n != 0)
	{
		dest[count--] = charset[n % base];
		n = n / base;
	}
	return (dest);
}

static int	itoa_count_num(int n)
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
	count = itoa_count_num(n);
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
int main(void)
{
	char *result = ft_uitoa_base(10, 2, "012456789ABCDEF");
	printf("%s\n", result);
	free(result);

	return (0);
}
*/