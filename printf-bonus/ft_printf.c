/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:08:53 by atardy            #+#    #+#             */
/*   Updated: 2026/10/15 12:08:53 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

char	*ft_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (0);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	cc;
	char	*str;

	cc = (char)c;
	str = (char *)s;
	while (n-- != 0)
	{
		if (*str == cc)
			return (str);
		str++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while ((*str == 32) || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str == 48)
		str++;
	while (*str && (*str >= 48 && *str <= 57))
	{
		result = result * 10 + (str[0] - 48);
		str++;
	}
	return (result * sign);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;
	size_t	total;

	if (size == 0 || count == 0)
		return (malloc(0));
	total = size * count;
	if (total / count != size)
		return (NULL);
	buffer = malloc (count * size);
	if (buffer == NULL)
		return (NULL);
	ft_bzero(buffer, (count * size));
	return (buffer);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}

int	bonus_hub (const char type, va_list *ap, t_flag *f)
{
	if (type == '%')
		return (write(1, "%", 1));
	else if (type == 's')
		return (putstr_va(va_arg(*ap, char*), f));
	else if (type == 'c')
		return (putchar_va(va_arg(*ap, int), f));
	else if (type == 'i' || type == 'd')
		return(hub_putnbr_i(type, ap, f));
	else if (type == 'u')
		return(hub_putnbr_u(type, ap, f));
	else if (type == 'x' || type == 'X')
		return(hub_putnbr_x(type, ap, f));
	else if (type == 'p')
		return (hub_putnbr_p(type, ap, f));
	return (0);
}

int	ft_printf(const char *text, ...)
{
	int		i;
	va_list	ap;
	t_flag	f;
	
	if (!(f.flags = ft_calloc (sizeof(char), 7)))
		return (0);
	va_start(ap, text);
	i = 0;
	while (*text)
	{
		if (*text != '%')
			i += write(1, text, 1);
		else
		{
			text++;
			i += flg_pars(text, &f, &ap);
			while (!ft_isalpha(*text))
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
// 	char	*str = "SALUT";
// 	char	*str2 = "FIN";
// 	int 	nb;
// 	unsigned int		unb;
// 	void	*ptr;
// 	char	c;

// 	nb = -2147483648;
// 	unb = 7483648;
// 	ptr = &nb;
// 	c = '9';
// 	// ptr = NULL;
// 	// printf ("\ni offi = %d\n", printf ("|%-+20s|",  str));
// 	printf ("\ni perso = %d\n", ft_printf ("|%#015.10p|", ptr));
// 	printf ("\ni offi = %d\n", printf ("|%#015.10p|", ptr));
	
// 	//	printf ("\nretour : %d\n", (printf ("|%+-20d|", nb)));
// 	return (0);
// }