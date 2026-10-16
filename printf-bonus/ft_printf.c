/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 00:16:47 by atardy            #+#    #+#             */
/*   Updated: 2026/10/17 00:20:20 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	bonus_hub(const char type, va_list *ap, t_flag *f)
{
	if (*(f->flags) == 0 && f->width < 0 && f->precision < 0)
		f = NULL;
	if (type == '%')
		return (write(1, "%", 1));
	if (type == 's')
		return (putstr_va(va_arg(*ap, char *), f));
	if (type == 'c')
		return (putchar_va(va_arg(*ap, int), f));
	if (type == 'i' || type == 'd')
		return (hub_putnbr_i(ap, f));
	if (type == 'u')
		return (hub_putnbr_u(ap, f));
	if (type == 'x' || type == 'X')
		return (hub_putnbr_x(type, ap, f));
	if (type == 'p')
		return (hub_putnbr_p(ap, f));
	return (0);
}

int	ft_printf(const char *text, ...)
{
	int		i;
	va_list	ap;
	t_flag	f;

	f.flags = ft_calloc (sizeof(char), 7);
	if (f.flags == NULL)
		return (0);
	va_start(ap, text);
	i = 0;
	while (*text)
	{
		if (*text != '%')
			i += write(1, text, 1);
		else if (*text == '%')
		{
			text++;
			i += flg_pars(text, &f, &ap);
			while (*text && !(ft_isalpha(*text) || *text == '%'))
				text++;
		}
		text++;
	}
	va_end(ap);
	free (f.flags);
	return (i);
}

// int	main(void)
// {
// 	// char	*str;

// 	// str = malloc(4); 
// 	// str[0] = 32;
// 	// str[1] = 32;
// 	// str[2] = 49;
// 	// str[3] = 0;

// 	// char	*str2 = "FIN";
// 	// int 	nb;
// 	// // unsigned int		unb;
// 	// void	*ptr;
// 	// // char	c;

// 	// nb = -5432532;
// 	// ptr = NULL;
// 	printf ("\ni perso = %d\n", ft_printf("%020.19dmade", 8000));
// 	printf ("\ni offi = %d\n", printf("%020.19dmade", 8000));

// 	//printf ("\ni perso = %d\n", ft_printf (" |%.2s |%.3s |%.4s 
		// // |%.5s |%.1s| ", " - ", "", "4", "", "2 "));
// 	// printf ("\ni offi = %d\n", printf (" |%4.2s|/|%.3s|/|%.4s
		// //	|/|%.5s|/|%.1s| ", " -      ", "ab", "4", "", "2 "));

// // 	str = NULL;
// // 	printf ("\ni offi = %d\n", printf  (" NULL %s NULL ", NULL));

// // // //	
// 	return (0);
// }