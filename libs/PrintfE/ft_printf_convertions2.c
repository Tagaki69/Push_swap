/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convertions2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wakhazza <wakhazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:17:25 by enzolarue         #+#    #+#             */
/*   Updated: 2026/01/28 14:56:13 by wakhazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	put_f(char *s)
{
	int	len;

	if (!s)
		return (0);
	len = (int)ft_strlen(s);
	ft_putstr_fd(s, 2);
	free(s);
	return (len);
}

int	handle_float(va_list args)
{
	double	n;
	long	i;
	long	d;
	int		c;

	n = va_arg(args, double);
	c = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', 2);
		c++;
		n = -n;
	}
	i = (long)n;
	d = (long)((n - i) * 100 + 0.5);
	i = i + (d / 100);
	d = d % 100;
	c = c + put_f(ft_itoa((int)i));
	ft_putchar_fd('.', 2);
	if (d < 10)
	{
		ft_putchar_fd('0', 2);
		c++;
	}
	return (c + 1 + put_f(ft_itoa((int)d)));
}
