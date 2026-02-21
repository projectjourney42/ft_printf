/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 10:52:02 by haranivo          #+#    #+#             */
/*   Updated: 2026/02/20 13:08:50 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_rev_char(char *str)
{
	int		i;
	int		len;
	char	tmp;

	len = ft_strlen((const char)str) - 1;
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
	ft_putstr_fd(str, 1);
}

void	ft_printf_hexa(unsigned int nbr, char type)
{
	int		tmp;
	int		hex;
	char	*hexa;

	while (nbr > 0)
	{
		tmp = nbr;
		nbr /= 16;
		hex = nbr % 16;
		if (hex > 9)
			*hexa = hex - 10 + 'a';
		else
			*hexa = hex + '0';
		hexa++;
	}
	ft_rev_char(hexa);
}
