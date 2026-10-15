/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 11:33:52 by atardy            #+#    #+#             */
/*   Updated: 2026/10/08 17:49:38 by atardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	uc1;
	unsigned char	uc2;

	i = 0;
	while (i < n)
	{
		uc1 = (unsigned char)s1[i];
		uc2 = (unsigned char)s2[i];
		if (uc1 != uc2)
			return (uc1 - uc2);
		if (uc1 == 0)
			return (0);
		i++;
	}
	return (0);
}

// int	main (void)
// {
// 	char	*s1;
// 	char	*s2;
// 	int		n;

// 	s1 = "Hey sAlut! Ça va?";
// 	s2 = "Hey salut! Ça va?";
// 	n = 5;
// 	// printf ("srtncmp : %d\n", strncmp(s1, s2, n));
// 	// printf ("ft_srtncmp : %d\n\n", ft_strncmp(s1, s2, n));
// 	printf ("srtncmp : %d\n", strncmp("\200", "\0", 1));
// 	printf ("ft_srtncmp : %d\n", ft_strncmp("\200", "\0", 1));
// 	// printf ("srtncmp : %d\n", strncmp("\207", "\200", 1));
// 	return (0);
// }
