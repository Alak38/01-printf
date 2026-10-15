/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_str_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 08:40:40 by atardy            #+#    #+#             */
/*   Updated: 2026/10/14 08:40:47 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putstr_va(char *s)
{
	int		i;
	
	i = 0;
	if (!s)
		return (write (1, "(null)", 6));
	while (*s)
	{
		i += write (1, s, 1);
		s++;
	}
	return (i);
}

int	putchar_va(int c)
{
	return (write (1, &c, 1));
}

int	putnbr_va(int nb, int i)
{
	if (nb == -2147483648)
		return (write (1, "-2147483648", 11));
	if (nb < 0)
	{
		i += write (1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
		i = putnbr_va(nb / 10, i);
	nb = (nb % 10) + 48;
	i += write (1, &nb, 1);
	return (i);
}

int	u_putnbr_va(unsigned int nb, int i)
{
	if (nb < 0)
	{
		i += write (1, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
		i = putnbr_va(nb / 10, i);
	nb = (nb % 10) + 48;
	i += write (1, &nb, 1);
	return (i);
}
