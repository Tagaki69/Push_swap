/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:50:34 by elarue            #+#    #+#             */
/*   Updated: 2025/11/13 11:12:02 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (fd < 0 || !s)
		return ;
	i = 0;
	while (s[i] != '\0')
		ft_putchar_fd(s[i++], fd);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_putstr_fd(argv[1], 1);
	return (0);
}
*/