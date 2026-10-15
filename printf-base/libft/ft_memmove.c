/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 11:31:31 by atardy            #+#    #+#             */
/*   Updated: 2026/10/08 15:37:10 by atardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (!dest || !src)
		return (NULL);
	i = -1;
	if (dest < src)
		while (++i < (int)n)
			((char *)dest)[i] = ((char *)src)[i];
	else
	{
		i = (int)n;
		while (--i >= 0)
		{
			((char *)dest)[i] = ((char *)src)[i];
		}
	}
	return (dest);
}

// #include <string.h>
// #include <unistd.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	src[36] = "123456789abcdefghijklmnopqrstuvwxyz";
// 	char	src2[36] = "123456789abcdefghijklmnopqrstuvwxyz";
// 	char	src3[36] = "123456789abcdefghijklmnopqrstuvwxyz";
// 	char	src4[36] = "123456789abcdefghijklmnopqrstuvwxyz";
// 	int		len;

// 	len = 20;
// 	write (1, "ft_memmove - dst > src : ", 26);
// 	ft_memmove((src3 + 3), (src3 + 0), len);
// 	write (1, src3, 36);
// 	write (1, "\n", 1);
// 	write (1, "   memmove - dst > src : ", 26);
// 	memmove((src + 3), (src + 0), len);
// 	write (1, src, 36);
// 	write (1, "\n", 1);
// 	write (1, "\n", 1);
// 	write (1, "ft_memmove - dst < src : ", 26);
// 	ft_memmove((src2 + 0), (src2 + 3), len);
// 	write (1, src2, 36);
// 	write (1, "\n", 1);
// 	write (1, "   memmove - dst < src : ", 26);
// 	memmove((src4 + 0), (src4 + 3), len);
// 	write (1, src4, 36);
// 	write (1, "\n", 1);
// }