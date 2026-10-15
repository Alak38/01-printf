/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:53:40 by atardy            #+#    #+#             */
/*   Updated: 2026/09/23 15:53:52 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_objects(char const *s, char c)
{
	int	in_word;
	int	i;
	int	count;

	i = -1;
	in_word = 0;
	count = 0;
	while (s[++i])
	{
		if (s[i] != c && in_word == 0)
		{
			count++;
			in_word = 1;
		}
		else if (s[i] == c && in_word == 1)
			in_word = 0;
	}
	return (count);
}

static int	alloc_copy(char **result, char const *s, char c, int n_str)
{
	int		i;
	int		j;
	char	*str;

	i = -1;
	str = (char *) s;
	while (++i < n_str)
	{
		j = 0;
		while (str[0] == c)
			str++;
		while (str[j] && str[j] != c)
			j++;
		result[i] = malloc (sizeof(char) * (j + 1));
		if (result[i] == NULL)
			return (i);
		j = 0;
		while (str[0] && str[0] != c)
		{
			result[i][j++] = str[0];
			str++;
		}
		result[i][j] = 0;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**result;
	int		i;

	count = count_objects(s, c);
	result = malloc (sizeof(char *) * (count + 1));
	if (result == NULL)
		return (NULL);
	result[count] = 0;
	i = alloc_copy(result, s, c, count);
	if (i != count)
	{
		while (i >= 0)
		{
			free (result[i]);
			i--;
		}
		free (result);
		return (NULL);
	}
	return (result);
}

// int	main(void)
// {
// 	char	separator;
// 	char	*string;
// 	char	**result;
// 	int		i;

// 	string = "AttAAtAAAtAAAAtAABAAttAABBAAtAABBBAAt";
// 	string = "a,b,c,d";
// 	separator = 't';
// 	separator = ',';
// 	result = ft_split(string, separator);
// 	i = -1;
// 	if (result != NULL)
// 		while (result[++i] != 0)
// 			printf ("string[%d] = %s\n", i, result[i]);
// 	else
// 		printf("result = NULL\n");
// 	return (0);
// }