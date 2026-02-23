/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 02:54:58 by haranivo          #+#    #+#             */
/*   Updated: 2026/02/09 17:04:44 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	int	len;
	int	i;

	len = ft_lstsize(lst);
	if (!lst)
		return (NULL);
	i = 0;
	while (i < len - 1)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
