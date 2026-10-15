/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 16:03:06 by atardy            #+#    #+#             */
/*   Updated: 2026/10/10 16:03:06 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	if (start > ft_strlen(s))
	{
		sub = ft_calloc (sizeof(char), 1);
		if (sub == NULL)
			return (NULL);
		return (sub);
	}
	if ((ft_strlen(s) - (size_t)start) < len)
		len = ft_strlen(s) - (size_t)start;
	sub = ft_calloc (sizeof(char), (size_t)(len + 1));
	if (sub == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = 0;
	return (sub);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*sub;
// 	int		start;
// 	int		len;

// 	start = 5;
// 	len = 10;
// 	printf ("start au char %d, len de %d\n", start, len);
// 	str = "p1 :  Salut ! | p2 : Mange tes morts! | p1 : maieuh!";
// 	sub = ft_substr(str, start, len);
// 	printf ("string longue : sub = %s\n", sub);
// 	printf ("char 0 present ? (si 0, oui) = %i\n", sub[len - 1]);
// 	free (sub);
// 	str = "p1 : FIN";
// 	sub = ft_substr(str, start, len);
// 	printf ("string courte : sub = %s\n", sub);
// 	printf ("char 0 present ? (si 0, oui) = %i\n", sub[9]);
// 	free (sub);
// }