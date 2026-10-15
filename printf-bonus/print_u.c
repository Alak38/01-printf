/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 11:21:52 by atardy            #+#    #+#             */
/*   Updated: 2026/10/15 11:22:31 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lu_putnbr_base(unsigned long int nb, int i, int base, int type)
{
	char	*b;

	b = "0123456789abcdef";
	if (type == 'X')
		b = "0123456789ABCDEF";
	if (nb >= (unsigned long int)base)
		i = lu_putnbr_base((nb / base), i, base, type);
	nb = b[(nb % base)];
	i += write (1, &nb, 1);
	return (i);
}

int	formating_u(t_flag *f, int len, unsigned int nb, int i)
{
	if (f)
	{
		if (ft_strchr(f->flags, '-'))
		{
			if (len < f->precision)
				i += write_zeroes (f->precision - len);
			i += lu_putnbr_base (nb, 0, 10, 'u');
			if (f->width >= 0 && f->width - i > 0)
				i += write_space ((f->width) - i);
			return (i);
		}
		else
		{
			if (f->precision > len)
				i += write_space (f->width - f->precision);
			else
				i += write_space (f->width - len);
			if (len < f->precision)
				i += write_zeroes (f->precision - len);
		}
	}
	i += lu_putnbr_base (nb, 0, 10, 'u');
	return (i);
}

int	hub_putnbr_u(va_list *ap, t_flag *f)
{
	unsigned int	u_nb;
	int				len;

	u_nb = va_arg(*ap, unsigned int);
	len = count_len_base(u_nb, 10);
	if (f && ft_strchr(f->flags, '0') && f->precision < 0)
		f->precision = f->width;
	return (formating_u(f, len, u_nb, 0));
}
