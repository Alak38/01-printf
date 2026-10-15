/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:55:00 by atardy            #+#    #+#             */
/*   Updated: 2026/10/15 12:55:14 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	formating_x2(t_flag *f, int len, unsigned long int nb, int type)
{
	int	i;
	int len_tot;

	i= 0;
	len_tot = len;
	if (f->precision > len)
	{
		if (ft_strchr(f->flags, '#'))
			len_tot = f->precision + 2;
		else
			len_tot = f->precision;
	}
	else if (f->precision < len && ft_strchr(f->flags, '#'))
		len_tot = len + 2;
	i += write_space (f->width - len_tot);
	if (ft_strchr(f->flags, '#') && type == 'X')
		i += write (1, "0X", 2);
	if (ft_strchr(f->flags, '#') && type == 'x')	
		i += write (1, "0x", 2);
	if (ft_strchr(f->flags, '#') && ft_strchr(f->flags, '0'))
		len += 2;
	i += write_zeroes (f->precision - len);
	i += lu_putnbr_base (nb, 0, 16, type);
		return (i);	
}

int	formating_x(t_flag *f, int len, long unsigned int nb, int type)
{
	int	i;

	i= 0;
	if (!f)
	{
		i += lu_putnbr_base (nb, 0, 16, type);
		return(i);
	}
	else if (ft_strchr(f->flags, '-'))
	{
		if (ft_strchr(f->flags, '#'))
		{
			if (type == 'X')
				i += write (1, "0X", 2);
			else
				i += write (1, "0x", 2);
		}
		if (len < f->precision)
			i += write_zeroes (f->precision - len);
		i += lu_putnbr_base (nb, 0, 16, 'u');
		if (f->width >= 0 && f->width - i > 0)
			i += write_space ((f->width) - i);
		return (i);
	}
	return (formating_x2(f, len, nb, type));
}

int	hub_putnbr_x(const char type, va_list *ap, t_flag *f)
{
	unsigned int		x_nb;
	long unsigned int	lx_nb;
	int					len;

	x_nb = va_arg(*ap, unsigned int);
	lx_nb = x_nb;
	len = count_len_base(lx_nb, 16);
	if (f && ft_strchr(f->flags, '0') && f->precision < 0)
		f->precision = f->width;
	return (formating_x(f, len, lx_nb, type));
}

int	nil(t_flag *f)
{
	int	i;

	i = 0;
	if (!f || f->width < 5)
		return (write(1, "(nil)", 5));
	if (ft_strchr(f->flags, '-'))
	{
		i += write(1, "(nil)", 5);
		i += write_space(f->width - i);
		return (i);
	}
	i += write_space(f->width - 5);
	i += write(1, "(nil)", 5);
	return (i);
}

int	hub_putnbr_p(va_list *ap, t_flag *f)
{
	long unsigned int	address;
	int					len;

	address = va_arg(*ap, long unsigned int);
	if (address == 0)
		return (nil(f));
	else
		len = count_len_base(address, 16);
	if (f && ft_strchr(f->flags, '0') && f->precision < 0)
		f->precision = f->width;
	if (!f)
	{
		write (1, "0x", 2);
		return (lu_putnbr_base (address, 0, 16, 'x') + 2);
	}
	f->flags[ft_strlen(f->flags)] = '#';
	return (formating_x(f, len, address, 'p'));
}