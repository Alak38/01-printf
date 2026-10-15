/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 21:57:13 by atardy            #+#    #+#             */
/*   Updated: 2026/10/14 21:57:13 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int hub (const char type, va_list *ap)
{
	if (type == '%')
		return (write(1, "%", 1));
	else if (type == 's')
		return (putstr_va(va_arg(*ap, char*)));
	else if (type == 'c')
		return (putchar_va(va_arg(*ap, int)));
	else if (type == 'i' || type == 'd')
		return (putnbr_va(va_arg(*ap, int), 0));
	else if (type == 'u')
		return (u_putnbr_va(va_arg(*ap, unsigned int), 0));
	else if (type == 'x' || type == 'X')
		return (putnbr_base(va_arg(*ap, unsigned int), 0, type));
	else if (type == 'p')
		return (ptr_print(va_arg(*ap, unsigned long int)));
	return (0);
}

int ft_printf(const char *text, ...)
{
	int		i;
	va_list	ap;
	
	va_start(ap, text);
	i = 0;
	while (*text)
	{
		if (*text != '%')
			i += write(1, text, 1);
		else
		{
			text++;
			i += hub (*text, &ap);
		}
		text++;
	}
	va_end(ap);
	return (i);
}

int	main(void)
{
	char	*str = "DEBUT";
	char	*str2 = "FIN";
	int 	nb;
	unsigned int		nb2;
	unsigned int		vid;
	void	*ptr;

	nb = -1u;
	ptr = &nb;
	vid = -1;
	nb = 0;
	nb2 = 3735929054;
	
	printf ("\ni perso = %d\n", ft_printf ("perso : %u || %p || %d || %s", vid, (unsigned int)3735929054, (unsigned int)3735929054, str2));
	printf ("\ni offi = %d\n", printf ("offi  : %u || %p || %d || %s", vid, (unsigned int)3735929054, (unsigned int)3735929054, str2));
	// printf ("\nretour : %d\n", (printf ("|%0-3d|", nb)));
	return (0);
}

// ATTENTION : (nil) ou 0x0 ???
