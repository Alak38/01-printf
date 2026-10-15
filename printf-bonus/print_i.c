/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 10:46:35 by atardy            #+#    #+#             */
/*   Updated: 2026/10/15 12:09:10 by atardy           ###   ########.ch       */
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


int	count_len_base(long unsigned int nb, int base)
{
	int	len;
	
	// printf ("\nnb = %lu(en val absolue)", nb);
	len = 0;
	while (nb != 0)
	{
		nb /= base;
		len++;
	}
	return (len);
}

int	formating_i2(t_flag *f, int len, int nb, int i)
{
	if (f && f->width >= 0)
	{
		if (f->precision >= 0 && f->precision > len)
			i += write_space (f->width - f->precision - 1);
		else
			i += write_space (f->width - len - 1);
		if (!((nb < 0) || (ft_strchr(f->flags, '+') && nb > 0) ||
			(ft_strchr(f->flags, ' ') && nb >= 0)))
			i += write_space(1);
	}
	if (nb < 0)
		i += write(1, "-", 1);
	else if (f && ft_strchr(f->flags, '+') && nb > 0)
		i += write(1, "+", 1);
	else if (f && ft_strchr(f->flags, ' ') && nb >= 0)
		i += write(1, " ", 1);
	if (f && len < f->precision)
		i += write_zeroes (f->precision - len);
	if (nb == -2147483648)
		i += write (1, "2147483648", 10);
	else
		i += putnbr (nb, 0);
	return (i);
}

int	formating_i(t_flag *f, int len, int nb, int i)
{
	if (f && ft_strchr(f->flags, '-'))
	{
		if (nb < 0)
			i += write(1, "-", 1);
		else if (ft_strchr(f->flags, '+') && nb > 0)
			i += write(1, "+", 1);
		else if (ft_strchr(f->flags, ' ') && nb >= 0)
			i += write(1, " ", 1);
		if (len < f->precision)
			i += write_zeroes (f->precision - len); 
		if (nb == -2147483648)
			i += write (1, "2147483648", 10);
		else 
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
		len = count_len_base(-nb, 10);
	else 
		len = count_len_base(nb, 10);
	if (f && ft_strchr(f->flags, '0') && f->precision < 0)
	{	
		if (ft_strchr(f->flags, '+') || ft_strchr(f->flags, ' ') || nb < 0)
			f->precision = f->width - 1;
		else
			f->precision = f->width;
	}
	return (formating_i(f, len, nb, 0));
}
