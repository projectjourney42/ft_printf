/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:05:46 by haranivo          #+#    #+#             */
/*   Updated: 2026/02/20 10:49:31 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_number(int nbr, char type)
{
	if (type == 'd' || type == 'i')
		ft_putnbr_fd(nbr, 1);
	else if (type == 'u')
		ft_printf_unsigned_nbr((unsigned int)nbr);
}
