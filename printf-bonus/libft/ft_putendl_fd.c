/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:54:18 by atardy            #+#    #+#             */
/*   Updated: 2026/09/23 15:54:29 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = -1;
	while (s[++i])
		write (fd, &s[i], 1);
	write (fd, "\n", 1);
}

// int	main(void)
// {
// 	char	*str;

// 	str = "Salut ! Ça semble bien marcher!";
// 	ft_putendl_fd(str, 1);
// 	return (0);
// }