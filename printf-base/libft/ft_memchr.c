/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 08:37:24 by atardy            #+#    #+#             */
/*   Updated: 2026/09/23 08:38:28 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	*str;
// 	char	*result;
// 	int		tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
// 	int		*result2;
// 	int		n;

// 	n = 11;
// 	str = "salut les Amis! Ca vA? Alak est dans la PlAce!";
// 	result = ft_memchr(str, 'A', n);
// 	printf ("result ft_memchr : %s\n", result);
// 	result = memchr(str, 'A', n);
// 	printf ("result memchr : %s\n", result);
// 	result2 = ft_memchr(tab, 11, (n * 4));
// 	if (result2 != 0)
// 		printf ("result int ft_memchr : %d & +\n", result2[0]);
// 	else
// 		printf ("result int ft_memchr : NULL\n");
// 	result2 = memchr(tab, 11, (n * 4));
// 	if (result2 != 0)
// 		printf ("result int memchr : %d & +\n", result2[0]);
// 	else
// 		printf ("result int ft_memchr : NULL\n");
// 	return (0);
// }