/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 13:17:17 by atardy            #+#    #+#             */
/*   Updated: 2026/10/09 14:00:42 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dst_len == 0 && dstsize == 0)
		return (src_len);
	if (dst_len > dstsize)
		return (src_len + dstsize);
	i = 0;
	while ((dst_len + i) < (dstsize - 1) && src[i] != 0)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len != 0)
		dst[dst_len + i] = 0;
	return (dst_len + src_len);
}

// int	main(void)
// {
// 	char	*src;
// 	char	dest[60] = "la congolexicomati";
// 	char	dest2[60] = "la congolexicomati";
// 	int		dstsize = -1;

// 	src = "sation des lois du marche!";
// 	printf ("ft_strlcat\n-> return val : %lu", ft_strlcat (dest, src, -1));
// 	printf (" | result : %s\n", dest);
// 	printf ("strlcat\n-> return val : %lu", strlcat (dest, src, dstsize));
// 	printf (" | result : %s\n", dest2);
// }