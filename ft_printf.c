/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:44:04 by haranivo          #+#    #+#             */
/*   Updated: 2026/02/23 00:13:15 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_which_print(const char *format, int i, va_list print)
{
	if (!format[i + 1])
				return (0);
	else if (format[i + 1] == '%')
		return (ft_putchar_fd('%', 1), 1);
	else if (format[i + 1] == 'c')
		return (ft_printf_char(va_arg(print, int)));
	else if (format[i + 1] == 's')
		return (ft_printf_string(va_arg(print, char	*)));
	else if (format[i + 1] == 'p')
		return (ft_printf_address(va_arg(print, void *)));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		return (ft_printf_number(va_arg(print, int), format[i + 1]));
	else if (format[i + 1] == 'u')
		return (ft_printf_unsigned_nbr(va_arg(print,unsigned int)))
	else if (format[i + 1] == 'x' || format[i + 1] == 'X')
		return(ft_printf_hexa(va_arg(print, unsigned int), format[i + 1]));
}

int	ft_printf(const char *format, ...)
{
	va_list	print;
	int		i;
	int	len;

	va_start(print, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += ft_which_print(format, i, print);
			i++;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			len++;
		}
		i++;
	}
	va_end(print);
	return (len)
}
