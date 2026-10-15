/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 16:07:01 by atardy            #+#    #+#             */
/*   Updated: 2026/10/10 16:10:52 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}

// // static void	ft_to_upper(unsigned int index, char *s)
// // {
// // 	if (s[index] >= 'a' && s[index] <= 'z')
// // 		s[index] = s[index] - 32;
// // }

// static void	iter(unsigned int i, char * s) 
// {
// 	s[i] += i;
// }

// int	main(void)
// {
// 	// char str[] = "j'aimerais bien la gueuler, cette phrase !";
// 	char s[] = "0000000000";

// 	// ft_striteri(str, ft_to_upper);
// 	// printf ("fct = to upper : %s\n", str);
// 	ft_striteri(s, iter);
// 	printf ("fct = iter : %s\n", s);
// 	printf ("si 0 : s est pareil que 0123456789 : %d", strcmp(s, "0123456789"));
// 	return (0);
// }