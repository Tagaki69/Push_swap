/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:54:04 by elarue            #+#    #+#             */
/*   Updated: 2025/11/27 13:54:04 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_uitoa_base(unsigned int n, int base, char *charset);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		handle_string(va_list args);
int		handle_char_percent(va_list args, const char format);
int		handle_int_uint(va_list args, const char format);
int		handle_hex(va_list args, const char format);
int		handle_pointer(va_list args);

#endif
