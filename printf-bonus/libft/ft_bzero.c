/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 11:29:53 by atardy            #+#    #+#             */
/*   Updated: 2026/10/14 10:29:41 by atardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// #include <string.h>
// #include <unistd.h>

// int	main(void)
// {
// 	int		str[15];
// 	int		str2[15];
// 	char	str3[15];
// 	char	str4[15];
// 	int		len;
// 	int		i;

// 	len = 10;
// 	ft_bzero(str, len);
// 	bzero(str2, len);
// 	ft_bzero(str3, len);
// 	bzero(str4, len);
// 	i = -1;
// 	while (++i < len)
// 	{	
// 		str[i] = str[i] + 48;
// 		write (1, &str[i], 1);
// 	}
// 	write (1, "\n", 1);
// 	i = -1;
// 	while (++i < len)
// 	{	
// 		str2[i] = str2[i] + 49;
// 		write (1, &str2[i], 1);
// 	}
// 	write (1, "\n", 1);
// 	i = -1;
// 	while (++i < len)
// 	{	
// 		str3[i] = str3[i] + 50;
// 		write (1, &str3[i], 1);
// 	}
// 	write (1, "\n", 1);
// 	i = -1;
// 	while (++i < len)
// 	{	
// 		str4[i] = str4[i] + 51;
// 		write (1, &str4[i], 1);
// 	}
// 	write (1, "\n", 1);
// 	return (0);
// }