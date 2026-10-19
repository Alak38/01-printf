/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 00:28:49 by atardy            #+#    #+#             */
/*   Updated: 2026/10/17 00:33:43 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_space(int n_space)
{
	int	i;

	if (n_space <= 0)
		return (0);
	i = 0;
	while (i < n_space)
	{
		write (1, " ", 1);
		i++;
	}
	return (i);
}

int	null(t_flag *f)
{
	int	i;
	int	len;

	i = 0;
	len = 6;
	if (f && !(f->precision < 0 || f->precision > 5))
		return(0);
	if (!f || f->width < 6)
		return (write(1, "(null)", len));
	if (ft_strchr(f->flags, '-'))
	{
		i += write(1, "(null)", len);
		i += write_space(f->width - i);
		return (i);
	}
	i += write_space(f->width - len);
	i += write(1, "(null)", len);
	return (i);
}

int	putstr_va(char *s, t_flag *f)
{
	int	i;
	int	len;

	if (!s)
		return (null(f));
	if (f && f->precision != -1 && (size_t)f->precision < ft_strlen (s))
		len = f->precision;
	else
		len = ft_strlen(s);
	if (f && f->width > len && ft_strchr(f->flags, '-'))
	{
		i = write (1, s, len);
		i += write_space ((f->width) - i);
		return (i);
	}
	if (f && f->width > len && !ft_strchr(f->flags, '-'))
	{
		i = write_space (f->width - len);
		i += write (1, s, len);
		return (i);
	}
	else
		return (write (1, s, len));
}

int	putchar_va(int c, t_flag *f)
{
	int	i;

	i = 0;
	if (f && f->width > 0)
	{
		if (ft_strchr(f->flags, '-'))
		{
			i += write (1, &c, 1);
			i += write_space (f->width - i);
			return (i);
		}
		else
		{
			i += write_space (f->width - 1);
			i += write (1, &c, 1);
			return (i);
		}
	}
	else
		i += write (1, &c, 1);
	return (i);
}
