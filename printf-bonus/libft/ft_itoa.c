/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 16:10:44 by atardy            #+#    #+#             */
/*   Updated: 2026/10/09 16:11:54 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recu_itoa(long nb, int index, char *str)
{
	if (nb > 9)
		recu_itoa(nb / 10, index -1, str);
	str[index] = ((nb % 10) + 48);
}

static int	count_len(int nb)
{
	int		len;
	long	n;

	len = 1;
	n = nb;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		len++;
	}
	if (n < 0)
		len++;
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nb;

	len = count_len(n);
	str = malloc ((sizeof(char) * len) + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nb = n;
		nb = nb * -1;
	}
	else
		nb = n;
	recu_itoa (nb, len - 1, str);
	str[len] = 0;
	return (str);
}

// int	main(void)
// {
// 	char	*res;
// 	int		n1;
// 	int		n2;

// 	n1 = 9324497;
// 	n2 = -904329;
// 	res = ft_itoa(n1);
// 	printf("Int en entré : %d | Str en sortie : %s\n", n1, res);
// 	res = ft_itoa(n2);
// 	printf("Int en entré : %d | Str en sortie : %s\n", n2, res);
// 	n1 = __INT32_MAX__;
// 	res = ft_itoa(n1);
// 	printf("Int en entré : %d | Str en sortie : %s\n", n1, res);
// 	n1 = ((__INT32_MAX__ * -1) - 1);
// 	res = ft_itoa(n1);
// 	printf("Int en entré : %d | Str en sortie : %s\n", n1, res);
// 	return(0);
// }