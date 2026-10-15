/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 11:32:14 by atardy            #+#    #+#             */
/*   Updated: 2026/10/07 11:32:16 by atardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*dup;

	len = 0;
	while (s1[len])
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		dup[i] = s1[i];
	dup[i] = s1[i];
	return (dup);
}

// #include <string.h>
// #include <stdio.h>

// int	main(void)
// {
// 	char	*str;
// 	char	*dup;
// 	char	*dup2;

// 	str = "Salut la compagnie! Ça roule";
// 	dup = ft_strdup(str);
// 	dup2 = strdup(str);
// 	printf ("perso : dup = %s\n", dup);
// 	printf ("offi : dup2 = %s\n", dup2);
// 	free(dup);
// 	free(dup2);
// }