/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:44:04 by haranivo          #+#    #+#             */
/*   Updated: 2026/02/20 10:51:05 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_which_print()

int	ft_printf(const char *format, ...)
{
	va_list	print;
	int		i;

	va_start(print, format);
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c' || format[i + 1] == 's')
				ft_printf_char(va_arg(print, char	*));
			else if (format[i + 1] == 'p')
				ft_printf_address(va_arg(print, void *));
			else if (format[i + 1] == 'd' || format[i + 1] == 'i' || format[i + 1] == 'u')
				ft_printf_number(va_arg(print, int), format[i + 1])
			else if (format[i + 1] == 'x' || format[i + 1] == 'X')
				ft_printf_hexa(va_arg(print, unsigned int));
			++ i;
		}
		else
			ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(print);
	// return counting qlqch
}
