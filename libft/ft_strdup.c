/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 10:31:54 by haranivo          #+#    #+#             */
/*   Updated: 2026/02/10 09:29:18 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		lensrc;

	lensrc = ft_strlen(s) + 1;
	dup = malloc(lensrc * sizeof(char));
	if (!dup)
		return (0);
	ft_memcpy(dup, s, lensrc);
	return (dup);
}
