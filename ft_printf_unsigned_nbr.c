/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned_nbr.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:49:09 by haranivo          #+#    #+#             */
/*   Updated: 2026/02/23 17:49:54 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int	ft_printf_unsigned_nbr(unsigned int nbr)
{
	if (nbr == 0)
		return (ft_putchar_fd('0', 1), 1);
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, 1);
		ft_putnbr_fd(nbr % 10, 1);
	}
	else
		ft_putchar_fd(nbr + '0', 1);
	return (ft_count(nbr));
}
