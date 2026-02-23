/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 17:20:07 by haranivo          #+#    #+#             */
/*   Updated: 2026/02/23 23:53:55 by haranivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf_string(char *s);
int		ft_count_long(unsigned long nbr);
int		ft_printf_lhexa(unsigned long add);
int		ft_printf_address(void *ptr);
int		ft_printf_number(int nbr, char type);
int		ft_printf_unsigned_nbr(unsigned int nbr);
int		ft_printf_hexa(unsigned int nbr, char type);
int		ft_printf(const char *format, ...);

void	ft_rev_char(char *str);

#endif