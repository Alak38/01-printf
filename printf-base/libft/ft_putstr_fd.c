/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 11:31:59 by atardy            #+#    #+#             */
/*   Updated: 2026/10/07 11:32:01 by atardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i])
		write (fd, &s[i], 1);
}

// int	main(void)
// {
// 	char	*str;

// 	str = "Salut ! Ça semble bien marcher!";
// 	ft_putstr_fd(str, 1);
// 	write (1, "\n", 1);
// 	return (0);
// }