/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 11:34:24 by atardy            #+#    #+#             */
/*   Updated: 2026/10/08 15:29:15 by atardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	if (!set)
		return (0);
	while (*set)
	{
		if (c == *set || c == '\0')
			return (1);
		set++;
	}
	return (0);
}

static int	find_len(char const *s1, char const *set)
{
	int	i;
	int	len;
	int	since_last;

	since_last = 0;
	i = 0;
	len = 0;
	while (s1[i])
	{
		if (is_in_set(s1[i], set) == 0 && since_last == 0)
			len++;
		if (is_in_set(s1[i], set) == 1)
			since_last++;
		if (is_in_set(s1[i], set) == 0 && since_last != 0)
		{
			len = len + since_last + 1;
			since_last = 0;
		}
		i++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		i;
	char	*str;

	if (!s1)
		return ((char *)s1);
	len = 0;
	while (*s1 && is_in_set(*s1, set) == 1)
		s1++;
	i = -1;
	if (*s1)
		len = find_len (s1, set);
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (str);
	str[len] = 0;
	while (++i < len)
	{
		str[i] = s1[i];
	}
	return (str);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*set;
// 	char	*result;

// 	set = "abcdef";
// 	str = "afSaLUT";
// 	result = ft_strtrim(str, set);
// 	printf ("set : %s || string : %s || result : %s\n\n", set, str, result);
// 	str = "SaLUTaba";
// 	result = ft_strtrim(str, set);
// 	printf ("set : %s || string : %s || result : %s\n\n", set, str, result);
// 	str = "afSaLUTfaaaaf";
// 	result = ft_strtrim(str, set);
// 	printf ("set : %s || string : %s || result : %s\n\n", set, str, result);
// 	str = "SaLUT";
// 	result = ft_strtrim(str, set);
// 	printf ("set : %s || string : %s || result : %s\n\n", set, str, result);
// 	str = NULL;
// 	result = ft_strtrim(str, set);
// 	printf ("set : %s || string : %s || result : %s\n\n", set, str, result);
// 	str = "";
// 	result = ft_strtrim(str, set);
// 	printf ("set : %s || string : %s || result : %s\n\n", set, str, result);
// 	str = "faSaLUTaf";
// 	set = NULL;
// 	result = ft_strtrim(str, set);
// 	printf ("set : %s || string : %s || result : %s\n\n", set, str, result);
// 	return (0);
// }