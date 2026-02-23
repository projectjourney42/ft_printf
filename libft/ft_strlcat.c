/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:15:03 by haranivo          #+#    #+#             */
/*   Updated: 2026/01/29 13:52:54 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lendest;
	size_t	lensrc;
	size_t	i;

	lendest = ft_strlen((const char *)dst);
	lensrc = ft_strlen(src);
	if (lendest >= size)
		return (size + lensrc);
	if (lendest < size - 1)
	{
		i = 0;
		while (src[i] && i < (size - lendest - 1))
		{
			dst[lendest + i] = src[i];
			i++;
		}
		dst[lendest + i] = 0;
	}
	return (lendest + lensrc);
}
