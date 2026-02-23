/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 15:18:17 by haranivo          #+#    #+#             */
/*   Updated: 2026/01/29 11:30:32 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	lastchr;

	lastchr = ft_strlen(s);
	while (lastchr)
	{
		if (s[lastchr] == (char)c)
			return ((char *)&s[lastchr]);
		lastchr--;
	}
	if (s[lastchr] != (char)c)
		return (0);
	return ((char *)&s[lastchr]);
}
