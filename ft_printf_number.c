/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:05:46 by haranivo          #+#    #+#             */
/*   Updated: 2026/02/23 17:52:20 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		i++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int	ft_printf_number(int nbr, char type)
{
	if (nbr == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		return (11);
	}
	if (nbr == 0)
		return (ft_putchar_fd('0', 1), 1);
	if (type == 'd' || type == 'i')
		ft_putnbr_fd(nbr, 1);
	return (ft_count(nbr));
}
