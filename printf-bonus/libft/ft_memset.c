/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 11:31:37 by atardy            #+#    #+#             */
/*   Updated: 2026/10/14 10:22:34 by atardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	c_plus;

	i = 0;
	c_plus = c;
	while (i < n)
	{
		*(char *)(s + i) = c_plus;
		i++;
	}
	return (s);
}

// #include <string.h>
// #include <unistd.h>

// int	main(void)
// {
// 	char	str3[15];
// 	int		str[15];
// 	int		str2[15];
// 	int		len;

// 	len = 3;
// 	ft_memset(str, 53, len);
// 	memset(str2, 53, len);
// 	ft_memset(str3, 53, len);
// 	write (1, str, len);
// 	write (1, "\n", 1);
// 	write (1, str2, len);
// 	write (1, "\n", 1);
// 	write (1, str3, len);
// 	write (1, "\n", 1);
// }