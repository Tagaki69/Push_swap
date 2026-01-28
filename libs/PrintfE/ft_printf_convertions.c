/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convertions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:26:38 by elarue            #+#    #+#             */
/*   Updated: 2025/11/27 14:40:49 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_string(va_list args)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	handle_char_percent(va_list args, const char format)
{
	char	c;

	if (format == '%')
		ft_putchar_fd('%', 1);
	else if (format == 'c')
	{
		c = va_arg(args, int);
		ft_putchar_fd(c, 1);
	}
	return (1);
}

int	handle_int_uint(va_list args, const char format)
{
	unsigned int	un;
	int				n;
	char			*str;
	int				len;

	if (format == 'i' || format == 'd')
	{
		n = va_arg(args, int);
		str = ft_itoa(n);
		if (!str)
			return (0);
	}
	else
	{
		un = va_arg(args, unsigned int);
		str = ft_uitoa_base(un, 10, "0123456789");
		if (!str)
			return (0);
	}
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int	handle_hex(va_list args, const char format)
{
	unsigned int	n;
	char			*str;
	int				len;

	str = NULL;
	n = va_arg(args, unsigned int);
	if (format == 'x')
	{
		str = ft_uitoa_base(n, 16, "0123456789abcdef");
		if (!str)
			return (0);
	}
	else if (format == 'X')
	{
		str = ft_uitoa_base(n, 16, "0123456789ABCDEF");
		if (!str)
			return (0);
	}
	if (!str)
		return (0);
	ft_putstr_fd(str, 1);
	len = ft_strlen(str);
	free(str);
	return (len);
}

int	handle_pointer(va_list args)
{
	void			*ptr;
	unsigned long	adress;
	char			*adress_str;
	unsigned long	len;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	adress = (unsigned long)ptr;
	adress_str = ft_uitoa_base(adress, 16, "0123456789abcdef");
	if (!adress_str)
		return (0);
	ft_putstr_fd("0x", 1);
	ft_putstr_fd(adress_str, 1);
	len = ft_strlen(adress_str);
	free(adress_str);
	return (len + 2);
}
