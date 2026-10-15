/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 12:57:57 by atardy            #+#    #+#             */
/*   Updated: 2026/10/09 13:14:39 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	if (!src)
		return (0);
	src_len = ft_strlen(src);
	if (!dst || !dstsize || dstsize <= 0)
		return (src_len);
	i = 0;
	while (i < (dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (src_len);
}

// int	main (void)
// {
// 	char	*src;
// 	char	dest[60];
// 	char	dest2[60];
// 	int		dstsize;

// 	src = "Salut les amis! Je suis à copier!";
// 	dstsize = 0;
// 	printf ("strlcpy \n return val : %lu", strlcpy (dest2, src, dstsize));
// 	printf (" | result : %s", dest2);
// 	printf (" | char n°45 : %c|\n", dest2[45] + 48);
// 	printf ("ft_strlcpy \n return val : %zu", ft_strlcpy (dest, src, dstsize));
// 	printf (" | result : %s", dest);
// 	printf (" | char n°45 : %c|\n", dest[45] + 48);
// }