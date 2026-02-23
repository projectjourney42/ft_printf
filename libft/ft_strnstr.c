/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:12:41 by haranivo          #+#    #+#             */
/*   Updated: 2026/02/03 21:49:31 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[i] == 0)
		return ((char *)&big[i]);
	while (big[i] && i < len)
	{
		j = 0;
		while ((little[j] && big[i + j] == little[j]) && i + j < len)
			j++;
		if (little[j] == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
