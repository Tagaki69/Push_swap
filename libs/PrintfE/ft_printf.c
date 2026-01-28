/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wakhazza <wakhazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:42:52 by elarue            #+#    #+#             */
/*   Updated: 2026/01/26 14:55:19 by wakhazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	process_conversion(char format, va_list args)
{
	int	count;

	count = 0;
	if (format == 'c' || format == '%')
		count = count + handle_char_percent(args, format);
	else if (format == 's')
		count = count + handle_string(args);
	else if (format == 'd' || format == 'i' || format == 'u')
		count = count + handle_int_uint(args, format);
	else if (format == 'x' || format == 'X')
		count = count + handle_hex(args, format);
	else if (format == 'p')
		count = count + handle_pointer(args);
	return (count);
}

int	parse_and_print(const char *format, va_list args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '.'
			&& format[i + 2] == '2' && format[i + 3] == 'f')
		{
			count = handle_float(args) + count;
			i += 4;
		}
		else if (format[i] == '%')
		{
			i++;
			count = process_conversion(format[i++], args) + count;
		}
		else
		{
			ft_putchar_fd(format[i++], 1);
			count++;
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = parse_and_print(format, args);
	va_end(args);
	return (count);
}

/*
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	len_ft;
	int	len_real;

	printf("=== TEST BASIQUE ===\n");
	ft_printf("Moi : %c | %s | %%\n", 'Z', "Ecole 42");
	printf("Vrai: %c | %s | %%\n", 'Z', "Ecole 42");
	printf("\n=== TEST NOMBRES ===\n");
	ft_printf("Moi : %d | %i | %u\n", 42, -2147483648, UINT_MAX);
	printf("Vrai: %d | %li | %u\n", 42, -2147483648, UINT_MAX);
	printf("\n=== TEST HEXA & POINTEURS ===\n");
	len_ft = ft_printf("Moi : %x | %X | %p | %p\n", 255, 255, 
					(void *)12345, NULL);
	len_real =  printf("Vrai: %x | %X | %p | %p\n", 255, 255, 
				(void *)12345, NULL);
	printf("\n=== TEST RETOUR (len) ===\n");
	printf("Moi retour : %d\n", len_ft);
	printf("Vrai retour: %d\n", len_real);

	return (0);
}
*/