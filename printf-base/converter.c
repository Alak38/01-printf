/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 08:35:24 by atardy            #+#    #+#             */
/*   Updated: 2026/10/14 08:35:24 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
static int	index_to_base (int nb, const char c)
{
	char	*base;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	return (write (1, &base[nb], 1));
}

int	putnbr_base(unsigned long int nb, int i, const char c)
{
	
	if (nb >= 16)
		i = putnbr_base(nb / 16, i, c);
	i += index_to_base(nb % 16, c);
	return (i);
}

int	ptr_print (unsigned long int adress)
{
	int					i;

	// if (!adress)
	// 	return(write(1, "(nil)", 5));
	i = write(1, "0x", 2);
	return (putnbr_base(adress, i, 'x'));
}