/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:08:45 by atardy            #+#    #+#             */
/*   Updated: 2026/10/15 12:08:45 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	precision(const char *s, t_flag *f, va_list *ap)
{
	char	*flag;
	s++;
	f->precision = ft_atoi(s);
	flag =ft_strchr((const void *)f->flags, '0');
	if (flag != 0)
		*flag = 1;
	while (!ft_isalpha(*s))
		s++;
	if (f->precision > f->width)
	{
		f->width = -1;
		if (ft_strchr(f->flags, '-'))
		{
			flag = ft_strchr(f->flags, '-');
			*flag = 1;
		}
	}
	return (bonus_hub (*s, ap, f));
}

int	width(const char *s, t_flag *f, va_list *ap)
{
	size_t	i;

	i = 0;
	if (ft_isalpha(*s))
	{
		f->width = -1;
		f->precision = -1;
		return (bonus_hub (*s, ap, f));
	}
	while (s[i] != '.' && !ft_isalpha(s[i]))
		i++;
	f->width = ft_atoi(s);
	s += i;
	if (ft_isalpha(*s))
	{
		f->precision = -1;
		return (bonus_hub (*s, ap, f));
	}
	return (precision(s, f, ap));
}

int	flg_pars(const char *s, t_flag *f, va_list *ap)
{
	char	*flag;
	int		i;

	f->width = -1;
	f->precision = -1;
	flag = "+ #-0";
	i = -1;
	while (s[++i] && !ft_isalpha(s[i]))
		if (s[i] == '%')
			return(bonus_hub (s[i], ap, f));
	i = 0;
	while (ft_strchr(flag, *s))
	{
		if (!ft_strchr(f->flags, *s))
			f->flags[i++] = *s;
		s++;
	}
	f->flags[i] = 0;
	flag = ft_strchr(f->flags, ' ');
	if (flag && ft_strchr(f->flags, '+') )
		*flag = 1;
	flag = ft_strchr(f->flags, '0');
	if (flag && ft_strchr(f->flags, '-') )
		*flag = 1;
	return (width(s, f, ap));
}