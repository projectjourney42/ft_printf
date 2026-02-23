/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 21:55:46 by haranivo          #+#    #+#             */
/*   Updated: 2026/02/10 09:26:38 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			word++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (word);
}

static char	**alloc_mem(int words)
{
	char	**tabstr;

	tabstr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tabstr)
		return (NULL);
	return (tabstr);
}

static void	*free_all(char **tabstr, int nbr)
{
	int	i;

	i = 0;
	while (nbr > i)
	{
		free(tabstr[i]);
		i++;
	}
	free(tabstr);
	return (NULL);
}

char	**ft_fill_up(char **splited, char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	word;

	word = 0;
	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		if (start < i)
		{
			splited[word] = ft_substr(s, start, i - start);
			if (!splited[word])
				return (free_all(splited, word));
			word++;
		}
	}
	splited[word] = NULL;
	return (splited);
}

char	**ft_split(char const *s, char c)
{
	char	**splited;

	if (!s)
		return (NULL);
	splited = alloc_mem(count_word(s, c));
	if (!splited)
		return (NULL);
	return (ft_fill_up(splited, s, c));
}
