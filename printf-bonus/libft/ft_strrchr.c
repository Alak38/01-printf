/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 21:10:18 by atardy            #+#    #+#             */
/*   Updated: 2026/10/09 11:45:12 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, char c)
{
	char	*result;
	int		i;

	if (!*s && c != 0)
		return (NULL);
	if (c == 0)
		return ((char *)&s[ft_strlen(s)]);
	i = 0;
	result = NULL;
	while (s[i])
	{
		if (s[i] == c)
			result = (char *)&s[i];
		s++;
	}
	if (s[i] == c)
		return ((char *)s);
	return (result);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*result;
// 	char	res0;

// 	str = "salut les Amis! Ca vA? Alak est dans la PlAce!";
// 	result = ft_strrchr(str, 'A');
// 	printf ("result ft_strrchr : %s\n", result);
// 	result = strrchr(str, 'A');
// 	printf ("result strrchr : %s\n", result);
// 	result = ft_strrchr(str, '\0');
// 	res0 = result[0] + 48;
// 	printf ("\nresult ft_strrchr - char = 0 : %c\n", res0);
// 	result = strrchr(str, '\0');
// 	res0 = result[0] + 48;
// 	printf ("\nresult strrchr - char = 0 : %c\n", res0);
// 	result = strrchr("", 'V');
// 	if (result == NULL)
// 		printf ("\nresult strrchr - str = NULL : NULL\n");
// 	result = ft_strrchr("", 'V');
// 	if (result == NULL)
// 		printf ("\nresult strrchr - str = NULL : NULL\n");
// 	return (0);
// }