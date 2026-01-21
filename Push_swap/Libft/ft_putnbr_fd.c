/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 09:56:58 by elarue            #+#    #+#             */
/*   Updated: 2025/11/13 10:12:46 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd(('-'), fd);
		n = n * -1;
	}
	if (n <= 9)
	{
		ft_putchar_fd((n + '0'), fd);
		return ;
	}
	else
	{
		ft_putnbr_fd((n / 10), fd);
	}
	ft_putchar_fd(((n % 10) + '0'), fd);
}
/*
int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_putnbr_fd(atoi(argv[1]), 1);
	return (0);
}
*/