/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 11:29:24 by atardy            #+#    #+#             */
/*   Updated: 2026/10/08 18:24:14 by atardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// int	main(void)
// {
// 	char	*str;
// 	int		result;

// 	// str = "1454a433";
// 	// result = atoi(str);
// 	// printf ("str = %s || result offi : %d\n", str, result);
// 	// result = ft_atoi(str);
// 	// printf ("str = %s || result perso : %d\n", str, result);
// 	// str = "-1455434a433";
// 	// result = atoi(str);
// 	// printf ("str = %s || result offi : %d\n", str, result);
// 	// result = ft_atoi(str);
// 	// printf ("str = %s || result perso : %d\n", str, result);
// 	// str = "  a1454a433";
// 	// result = atoi(str);
// 	// printf ("str = %s || result offi : %d\n", str, result);
// 	// result = ft_atoi(str);
// 	// printf ("str = %s || result perso : %d\n", str, result);
// 	str = "  +143432443";
// 	result = atoi(str);
// 	printf ("str = %s || result offi : %d\n", str, result);
// 	result = ft_atoi(str);
// 	printf ("str = %s || result perso : %d\n", str, result);
// }