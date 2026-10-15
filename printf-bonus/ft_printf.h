/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:10:14 by atardy            #+#    #+#             */
/*   Updated: 2026/10/15 12:15:25 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

// pour les tests:
# include <stdio.h>


typedef struct s_flag
{
	char	*flags;
	int		width;
	int		precision;
}				t_flag;

int	flg_pars(const char *s, t_flag *f, va_list *ap);
int	width(const char *s, t_flag *f, va_list *ap);
int	precision(const char *s, t_flag *f, va_list *ap);
int	bonus_hub (const char type, va_list *ap, t_flag *f);
int	ft_printf(const char *text, ...);
int	write_space(int	n_space);
int	putstr_va(char *s, t_flag *f);
int	putchar_va(int c, t_flag *f);
int	putnbr(int n, int i);
int	write_zeroes(int n_space);
int	count_len_base(long unsigned int nb, int base);
int	formating_i2(t_flag *f, int len, int nb, int i);
int	formating_i(t_flag *f, int len, int nb, int i);
int	hub_putnbr_i(const char type, va_list *ap, t_flag *f);
int	lu_putnbr_base(unsigned long int nb, int i, int base, int type);
int	formating_u(t_flag *f, int len, unsigned int nb, int i);
int	hub_putnbr_u(const char type, va_list *ap, t_flag *f);
int	hub_putnbr_p(const char type, va_list *ap, t_flag *f);
int	hub_putnbr_x(const char type, va_list *ap, t_flag *f);
int	formating_x(t_flag *f, int len, unsigned long int nb, int type);
int	formating_x2(t_flag *f, int len, unsigned long int nb, int type);

#endif
