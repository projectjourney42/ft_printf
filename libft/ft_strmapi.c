/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 02:24:42 by haranivo          #+#    #+#             */
/*   Updated: 2026/02/08 11:55:54 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*modif;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	modif = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!modif)
		return (NULL);
	i = 0;
	while (s[i])
	{
		modif[i] = (*f)(i, s[i]);
		i++;
	}
	modif[i] = '\0';
	return (modif);
}
