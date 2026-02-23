/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 13:15:16 by haranivo          #+#    #+#             */
/*   Updated: 2026/02/11 14:03:06 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_itoa(int n)
{
	char	*a;
	size_t	length;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	length = ft_count(n);
	a = malloc(sizeof(char) * (length + 1));
	if (!a)
		return (NULL);
	a[length] = '\0';
	if (n < 0)
	{
		a[0] = '-';
		n = -n;
	}
	a[length] = '\0';
	while (n > 0)
	{
		a[--length] = n % 10 + '0';
		n /= 10;
	}
	return (a);
}
