/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 11:31:44 by atardy            #+#    #+#             */
/*   Updated: 2026/10/08 10:43:08 by atardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}

// int	main(void)
// {
// 	int fd;

// 	fd = open ("test", O_RDWR);
// 	ft_putchar_fd('a', fd);
// 	ft_putchar_fd('\n', fd);
// 	close (fd);
// 	return (0);
// }