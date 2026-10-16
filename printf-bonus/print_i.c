/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 00:14:13 by atardy            #+#    #+#             */
/*   Updated: 2026/10/17 00:15:54 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putnbr(int n, int i)
{
	if (n > 9 || n < -9)
		i = putnbr((n / 10), i);
	n = (n % 10);
	if (n < 0)
		n *= -1;
	n += 48;
	i += write (1, &n, 1);
	return (i);
}

int	formating_i3(t_flag *f, int len, int nb, int i)
{
	if (nb < 0)
		i += write(1, "-", 1);
	else if (f && ft_strchr(f->flags, '+') && nb >= 0)
		i += write(1, "+", 1);
	else if (f && ft_strchr(f->flags, ' ') && nb >= 0)
		i += write(1, " ", 1);
	if (f)
		i += write_zeroes (f->precision - len);
	if (nb == -2147483648)
		i += write (1, "2147483648", 10);
	else if (len != 0)
		i += putnbr (nb, 0);
	return (i);
}

int	formating_i2(t_flag *f, int len, int nb, int i)
{
	int	n_space;

	n_space = 0;
	if (f && f->width >= 0)
	{
		if (f->precision > len)
			n_space = f->width - f->precision - 1;
		else
			n_space = f->width - len - 1;
		if ((nb > 0 && !ft_strchr(f->flags, '+') && !ft_strchr(f->flags, ' '))
			|| (f->precision == 0 && nb == 0))
			n_space++;
		i += write_space(n_space);
	}
	return (formating_i3(f, len, nb, i));
}

int	formating_i(t_flag *f, int len, int nb, int i)
{
	if (f && ft_strchr(f->flags, '-'))
	{
		if (nb < 0)
			i += write(1, "-", 1);
		else if (ft_strchr(f->flags, '+') && nb >= 0)
			i += write(1, "+", 1);
		else if (ft_strchr(f->flags, ' ') && nb >= 0)
			i += write(1, " ", 1);
		if (len < f->precision)
			i += write_zeroes (f->precision - len);
		if (nb == -2147483648)
			i += write (1, "2147483648", 10);
		else if (len != 0)
			i += putnbr (nb, 0);
		if (f->width >= 0 && f->width - i > 0)
			i += write_space ((f->width) - i);
		return (i);
	}
	return (formating_i2(f, len, nb, 0));
}

int	hub_putnbr_i(va_list *ap, t_flag *f)
{
	int				len;
	int				nb;

	nb = va_arg(*ap, int);
	if (nb == -2147483648)
		len = 10;
	else if (nb < 0)
		len = count_len_base(-nb, f, 10);
	else
		len = count_len_base(nb, f, 10);
	if (f && ft_strchr(f->flags, '0') && f->precision < 0)
	{
		if (ft_strchr(f->flags, '+') || ft_strchr(f->flags, ' ') || nb < 0)
			f->precision = f->width - 1;
		else
			f->precision = f->width;
		f->width = -1;
	}
	return (formating_i(f, len, nb, 0));
}
