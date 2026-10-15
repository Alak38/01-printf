/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 11:32:09 by atardy            #+#    #+#             */
/*   Updated: 2026/10/08 16:07:35 by atardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&s[i]);
	return (0);
}

// int	main(void)
// {
// 	char	*str;
// 	char	*result;

// 	str = "salut les Amis! Ca vA? Alak est dans la PlAce!";
// 	result = ft_strchr(str, 'A');
// 	printf ("result ft_strchr : %s\n", result);
// 	result = strchr(str, 'A');
// 	printf ("result strchr : %s\n", result);
// 	return (0);
// }