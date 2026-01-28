/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:17:35 by elarue            #+#    #+#             */
/*   Updated: 2025/11/13 11:41:38 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (s == 0 || f == 0)
		return ;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>
void uppercase(unsigned int index,char *c)
{
	(void) index;
	if (*c >= 'a' && *c <= 'z')
	*c = *c - 32;
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_striteri(argv[1], uppercase);
		printf("%s\n", argv[1]);
	}
	return (0);
}
*/