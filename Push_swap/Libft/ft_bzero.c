/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 08:59:59 by elarue            #+#    #+#             */
/*   Updated: 2025/11/12 12:01:15 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return ;
	while (i < n)
		((unsigned char *)s)[i++] = 0;
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		char s[] = "Hello everybody";
		ft_bzero(s, atoi(argv[1]));
		while (i < 15)
		{
			if (s[i] == 0)
			printf("0");
			else
			printf("%c", s[i]);
			i++;
		}
	}
	return (0);
}
*/