/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 20:40:52 by haranivo          #+#    #+#             */
/*   Updated: 2026/02/23 15:02:19 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

static void	ft_hexa(unsigned int nbr, char type)
{
	int		hex;
	int		i;
	char	*hexa;

	hexa = malloc(sizeof(char) * (ft_count(nbr) + 1));
	if (!hexa)
		return ;
	i = 0;
	while (nbr > 0)
	{
		hex = nbr % 16;
		nbr /= 16;
		if (hex > 9 && type == 'x')
			hexa[i] = hex - 10 + 'a';
		else if (hex > 9 && type == 'X')
			hexa[i] = hex - 10 + 'A';
		else
			hexa[i] = hex + '0';
		i++;
	}
	hexa[i] = '\0';
	ft_rev_char(hexa);
	free(hexa);
}

int	ft_printf_hexa(unsigned int nbr, char type)
{
	if (nbr == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	ft_hexa(nbr, type);
	return (ft_count(nbr));
}

// #include <stdio.h>

// int main(void)
// {
// 	unsigned int n = 4294967295;

// 	printf("Original printf x  : %x\n", n);
// 	printf("Original printf X  : %X\n", n);

// 	ft_printf_hexa(n, 'x');
// 	write(1, "\n", 1);

// 	ft_printf_hexa(n, 'X');
// 	write(1, "\n", 1);

// 	ft_printf_hexa(0, 'x');
// 	write(1, "\n", 1);

// 	printf("\nft_printf return (%d\n", ft_printf_hexa(n, 'x')));
// 	printf("\nft_printf return (%d\n", ft_printf_hexa(0, 'x')));
// 	return (0);
// }
