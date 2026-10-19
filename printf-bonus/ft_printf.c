/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 09:12:42 by atardy            #+#    #+#             */
/*   Updated: 2026/10/17 09:30:12 by atardy           ###   ########.ch       */
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
// 	printf ("\ntest de base\n");
// 	printf ("\ni perso = %d\n", ft_printf("retour perso |%c|/|%s|/|%d|/|%u|/|%x|/|%X|/|%p|", 'a', "SALUT", -912, 912, 912, 912, &printf));
// 	printf ("\ni offic = %d\n", printf("retour offic |%c|/|%s|/|%d|/|%u|/|%x|/|%X|/|%p|", 'a', "SALUT", -912, 912, 912, 912, &printf));
// 	printf ("\ntest avec %%s et largueur > précision\n");
// 	printf ("\ni perso = %d\n", ft_printf("retour perso |%10.5s|", "Salut!Yo!"));
// 	printf ("\ni offic = %d\n", printf("retour offic |%10.5s|", "Salut!Yo!"));
// 	printf ("\ntest avec %%s et largueur < précision\n");
// 	printf ("\ni perso = %d\n", ft_printf("retour perso |%5.10s|", "Salut!Yo!"));
// 	printf ("\ni offic = %d\n", printf("retour offic |%5.10s|", "Salut!Yo!"));
// 	printf ("\ntest avec %%d et largueur > précision\n");
// 	printf ("\ni perso = %d\n", ft_printf("retour perso |%10.5d|", 912));
// 	printf ("\ni offic = %d\n", printf("retour offic |%10.5d|", 912));
// 	printf ("\ntest avec %%d et largueur < précision\n");
// 	printf ("\ni perso = %d\n", ft_printf("retour perso |%5.10d|", 912));
// 	printf ("\ni offic = %d\n", printf("retour offic |%5.10d|", 912));
// 	printf ("\ntest %%x avec # puis # et -\n");
// 	printf ("\ni perso = %d\n", ft_printf("retour perso |%#x| |%#-10x|", 912, 912));
// 	printf ("\ni offic = %d\n", printf("retour offic |%#x| |%-#10x|", 912, 912));
// 	printf ("\nla même avec %%X\n");
// 	printf ("\ni perso = %d\n", ft_printf("retour perso |%#X| |%#-10X|", 912, 912));
// 	printf ("\ni offic = %d\n", printf("retour offic |%#X| |%-#10X|", 912, 912));
// 	return (0);
// }