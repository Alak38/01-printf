/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 14:07:50 by atardy            #+#    #+#             */
/*   Updated: 2026/10/09 14:21:21 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	ndl;
	size_t	ndl_len;

	if (!needle)
		return ((char *) hay);
	ndl_len = ft_strlen (needle);
	if (*needle == 0)
		return ((char *)&hay[ndl_len]);
	if (*hay == 0)
		return (0);
	while (hay[ndl_len - 1] && ndl_len <= len)
	{
		ndl = 0;
		while (ndl < ndl_len && needle[ndl] == hay[ndl])
			ndl++;
		if (ndl == ndl_len)
			return ((char *)hay);
		hay++;
		len--;
	}
	return (0);
}

//int	main(void)
//{
//	char	*big;
//	char	*little;
//	char	*result;
//	int		len;

//	big = "salutcoucousalut";
//	little = "coucou";
//	len = -1;
//	result = strnstr(big, little, len);
//	printf ("result offi : %s\n", result);
//	result = ft_strnstr(big, little, len);
//	printf ("result perso : %s\n", result);
//	return (0);
//}