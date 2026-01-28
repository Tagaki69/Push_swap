/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:39:37 by elarue            #+#    #+#             */
/*   Updated: 2025/09/24 11:38:24 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *str, const char *to_find)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	if (to_find[j] == '\0')
		return ((char *)&str[i]);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			j++;
			if (to_find[j] == '\0')
			{
				return ((char *)&str[i]);
			}
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "babaf fdf";
	char	to_find[] = "baba";

	printf("%s", ft_strstr(str, to_find));
	return (0);
}
*/
