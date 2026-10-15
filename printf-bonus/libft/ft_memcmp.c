/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 11:31:18 by atardy            #+#    #+#             */
/*   Updated: 2026/10/07 13:57:00 by atardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	while (n-- > 0)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (0);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;
// 	int		t1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
// 	int		t2[] = {1, 2, 3, 4, 52, 6, 7, 8, 9, 10};
// 	int		n;

// 	s1 = "Hey Salut!";
// 	s2 = "Hey salut!";
// 	n = 5;
// 	printf ("ft_memcmp : %d\n", ft_memcmp(s1, s2, n));
// 	printf ("memcmp : %d\n", memcmp(s1, s2, n));
// 	printf ("ft_memcmp : %d\n", ft_memcmp(t1, t2, (n * 4)));
// 	printf ("memcmp : %d\n", memcmp(t1, t2, n * 4));
// 	return (0);
// }
