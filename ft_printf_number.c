/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:05:46 by haranivo          #+#    #+#             */
/*   Updated: 2026/02/22 23:06:59 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_count(int nbr)
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
int	ft_printf_number(int nbr, char type)
{
	if (type == 'd' || type == 'i')
		ft_putnbr_fd(nbr, 1);
	return (ft_count(nbr));
}
