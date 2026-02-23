/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lhexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 22:11:26 by haranivo          #+#    #+#             */
/*   Updated: 2026/02/23 14:46:28 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_lhexa(unsigned long add)
{
	int		hex;
	int		i;
	char	*hexa;

	hexa = malloc(sizeof(char) * (ft_count_long(add) + 1));
	if (!hexa)
		return ;
	i = 0;
	while (add > 0)
	{
		hex = add % 16;
		add /= 16;
		if (hex > 9)
			hexa[i] = hex - 10 + 'a';
		else
			hexa[i] = hex + '0';
		i++;
	}
	hexa[i] = '\0';
	ft_rev_char(hexa);
	free(hexa);
}

int	ft_printf_lhexa(unsigned long add)
{
	ft_lhexa(add);
	return (ft_count_long(add));
}
