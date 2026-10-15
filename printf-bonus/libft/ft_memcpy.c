/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 11:31:25 by atardy            #+#    #+#             */
/*   Updated: 2026/10/14 10:29:46 by atardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

// #include <string.h>
// #include <unistd.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	src3[36] = "123456789abcdefghijklmnopqrstuvwxyz";
// 	int		len;

// 	len = 20;
// 	write (1, "ft_memcpy : ", 13);
// 	ft_memcpy((src3 + 2), (src3 + 0), len);
// 	write (1, src3, 36);
// 	write (1, "\n", 1);
// }