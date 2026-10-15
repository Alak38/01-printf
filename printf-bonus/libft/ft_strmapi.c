/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 08:32:34 by atardy            #+#    #+#             */
/*   Updated: 2026/09/23 08:32:34 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	i;
	char			*res;

	if (!f || !s)
		return (NULL);
	len = ft_strlen(s);
	res = malloc (sizeof(char) * len + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}

// static char	ft_is_digit(unsigned int index, char c)
// {
// 	(void) index;
// 	if (c >= '0' && c <= '9')
// 		return ('1');
// 	else
// 		return ('0');
// }

// static char	ft_to_lower(unsigned int index, char c)
// {
// 	(void) index;
// 	if (c >= 65 && c <= 90)
// 		c = c + 32;
// 	return (c);
// }

// int	main(void)
// {
// 	char	*str;
// 	char	*res;

// 	str = "a2b2AFG9a3";
// 	res = ft_strmapi(str, ft_is_digit);
// 	printf("str = %s\n", str);
// 	printf("fct : isdigit || res = %s\n", res);
// 	res = ft_strmapi(str, ft_to_lower);
// 	printf("fct : tolower || res = %s\n", res);
// 	printf("str = %s\n", str);
// 	return (0);
// }