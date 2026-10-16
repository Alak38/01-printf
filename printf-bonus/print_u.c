/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 00:16:05 by atardy            #+#    #+#             */
/*   Updated: 2026/10/17 00:16:32 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_len_base(long unsigned int nb, t_flag *f, int base)
{
	int	len;

	len = 0;
	if (nb == 0 && f->precision == 0)
		return (0);
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

int	write_zeroes(int n_space)
{
	int	i;

	i = 0;
	if (n_space <= 0)
		return (0);
	while (i < n_space)
	{
		write (1, "0", 1);
		i++;
	}
	return (i);
}

int	lu_putnbr_base(unsigned long int nb, int i, int base, int type)
{
	char	*b;

	if (type == 'X')
		b = "0123456789ABCDEF";
	else
		b = "0123456789abcdef";
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
			if (len)
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
	if (len)
		i += lu_putnbr_base (nb, 0, 10, 'u');
	return (i);
}

int	hub_putnbr_u(va_list *ap, t_flag *f)
{
	unsigned int	u_nb;
	int				len;

	u_nb = va_arg(*ap, unsigned int);
	len = count_len_base(u_nb, f, 10);
	if (f && ft_strchr(f->flags, '0') && f->precision < 0)
		f->precision = f->width;
	return (formating_u(f, len, u_nb, 0));
}
