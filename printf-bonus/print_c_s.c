/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:08:59 by atardy            #+#    #+#             */
/*   Updated: 2026/10/15 12:08:59 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	write_space(int	n_space)
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

int	putstr_va(char *s, t_flag *f)
{
	int		i;

	i = 0;
	if (!s)
		s = "(null)";
	if (f && f->width != -1 && (size_t)f->width > ft_strlen (s))
		if (ft_strchr(f->flags, '-'))
		{
			i = write (1, s, ft_strlen (s));
			i += write_space ((f->width) - i);
			return (i);
		}
		else
		{
			i = write_space (f->width - ft_strlen (s));
			i += write (1, s, ft_strlen (s));
			return (i);
		}
	else
		i += write (1, s, ft_strlen (s));
	return (i);
}

int	putchar_va(int c, t_flag *f)
{
	int	i;

	i = 0;
	if (f && f->width != -1)
		if (ft_strchr(f->flags, '-'))
		{
			i = write (1, &c, 1);
			i += write_space ((f->width) - i);
			return (i);
		}
		else
		{
			i = write_space (f->width - 1);
			i += write (1, &c, 1);
			return (i);
		}
	else
		i = write (1, &c, 1);
	return (i);
}