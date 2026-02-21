/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:26:12 by haranivo          #+#    #+#             */
/*   Updated: 2026/02/20 10:44:53 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_char(char *arg, char type)
{
	if (type == 'c')
		ft_putchar_fd(*arg, 1);
	else if (type == 's')
		ft_putstr_fd(arg, 1);
}