/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 09:19:14 by haranivo          #+#    #+#             */
/*   Updated: 2026/01/29 15:05:45 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*org;
	unsigned char	*dst;

	org = (unsigned char *)src;
	dst = (unsigned char *)dest;
	if (dst < org)
		ft_memcpy(dst, org, n);
	while (dst > org && n > 0)
	{
		dst[n - 1] = org[n - 1];
		n--;
	}
	return (dest);
}
