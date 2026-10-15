/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 17:42:10 by atardy            #+#    #+#             */
/*   Updated: 2026/10/13 17:44:52 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
// pour les tests:
# include <stdio.h>
# include <string.h>

int	ft_printf(const char *text, ...);
int	putstr_va(char *s);
int	putchar_va(int c);
int	putnbr_va(int nb, int i);
int	u_putnbr_va(unsigned int nb, int i);
int	putnbr_base(unsigned long int nb, int i, char c);
int	ptr_print (unsigned long int adress);

typedef struct s_flag
{
	char	*flags;
	int		width;
	int		precision;
}				t_flag;

#endif
