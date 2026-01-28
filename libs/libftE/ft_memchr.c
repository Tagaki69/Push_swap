/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:36:55 by elarue            #+#    #+#             */
/*   Updated: 2025/11/12 10:25:26 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((const unsigned char *)s)[i] == (unsigned char) c)
			return ((void *)&((const unsigned char *)s)[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
	if (argc == 3)
	{
		char s[] = "hello everybody";
		void *result;

		result = ft_memchr(s, argv[1][0], atoi(argv[2]));
		if (result != 0)
			printf("%s\n", (char *)result);
		else
			printf("non trouve");
	}
	return (0);
}
*/