/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_address.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 21:38:10 by haranivo          #+#    #+#             */
/*   Updated: 2026/02/22 22:47:43 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_address(void *ptr)
{
    unsigned long add;

    add = (unsigned long)ptr;
    if (!ptr)
    {
        ft_putstr_fd("(nil)", 1);
        return (5);
    }
    ft_putstr_fd("0x", 1);
    ft_printf_lhexa(add);
    return (ft_count_long(add) + 2);
}