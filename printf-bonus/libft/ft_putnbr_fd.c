/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 11:31:54 by atardy            #+#    #+#             */
/*   Updated: 2026/10/07 11:31:55 by atardy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write (fd, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	nb = (nb % 10) + 48;
	write (fd, &nb, 1);
}

// int	main(void)
// {
// 	int	nb;

// 	nb = -1234329;
// 	write (1, "Entrée = -1234329 || Sortie = ", 32);
// 	ft_putnbr_fd(nb, 1);
// 	write (1, "\n", 1);
// 	nb = 9234329;
// 	write (1, "Entrée = 9234329 || Sortie = ", 31);
// 	ft_putnbr_fd(nb, 1);
// 	write (1, "\n", 1);
// 	return (0);
// }