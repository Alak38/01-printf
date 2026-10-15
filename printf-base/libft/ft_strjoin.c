/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:51:57 by atardy            #+#    #+#             */
/*   Updated: 2026/09/23 15:51:57 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len1;
	size_t		len2;
	char		*result;
	int			i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = ft_calloc(1, len1 + len2 + 1);
	if (result == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	while (*s2)
	{
		result[i++] = *s2;
		s2++;
	}
	result[i] = 0;
	return (result);
}

// int	main(void)
// {
// 	char	*str1;
// 	char	*str2;

// 	str1 = "Salut les Am";
// 	str2 = "oureux! Et pas les amis pour une fois!";
// 	str1 = ft_strjoin(str1, str2);
// 	printf ("resultat : %s\n", str1);
// 	free (str1);
// }