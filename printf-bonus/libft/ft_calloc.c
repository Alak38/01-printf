/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 14:24:33 by atardy            #+#    #+#             */
/*   Updated: 2026/10/09 15:37:29 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;
	size_t	total;

	if (size == 0 || count == 0)
		return (malloc(0));
	total = size * count;
	if (total / count != size)
		return (NULL);
	buffer = malloc (count * size);
	if (buffer == NULL)
		return (NULL);
	ft_bzero(buffer, (count * size));
	return (buffer);
}

// int	main(void)
// {
// 	char	*result_c;
// 	int		*result_i;
// 	int		count;
// 	int		size;
// 	int		i;

// 	count = 2;
// 	size = 2;
// 	result_c = calloc(count, size);
// 	result_i = calloc(count, size);
// 	i = -1;
// 	//OFFI_CHAR _______
// 	printf ("OFFI\ncontenu de result_c :");
// 	while (++i < (size * count))
// 	{
// 		printf("%c, ",(result_c[i] + 48));
// 		result_c[i] = (i + 48); 
// 	}
// 	i = -1;
// 	printf ("\nresult_c après transfo:");
// 	while (++i < (size * count))
// 		printf("%c, ",(result_c[i]));
// 	//OFFI_INT _______
// 	printf ("\n\ncontenu de result_i :");
// 	i = -1;
// 	while (++i < ((size * count) / (int)sizeof(int)))
// 	{
// 		printf("%d, ",(result_i[i]));
// 		result_i[i] = (i); 
// 	}
// 	i = -1;
// 	printf ("\nresult_i après transfo:");
// 	while (++i < ((size * count) / (int)sizeof(int)))
// 		printf("%d, ",(result_i[i]));

// 	result_c = ft_calloc(count, size);
// 	result_i = ft_calloc(count, size);
// 	//PERSO_CHAR _______
// 	i = -1;
// 	printf ("\n\nPERSO \ncontenu de result_c :");
// 	while (++i < (size * count))
// 	{
// 		printf("%c, ",(result_c[i] + 48));
// 		result_c[i] = (i + 48); 
// 	}
// 	i = -1;
// 	printf ("\nresult_c après transfo:");
// 	while (++i < (size * count))
// 		printf("%c, ",(result_c[i]));
// 	//PERSO_INT _______
// 	printf ("\n\ncontenu de result_i :");
// 	i = -1;
// 	while (++i < ((size * count) / (int)sizeof(int)))
// 	{
// 		printf("%d, ",(result_i[i]));
// 		result_i[i] = (i); 
// 	}
// 	i = -1;
// 	printf ("\nresult_i après transfo:");
// 	while (++i < ((size * count) / (int)sizeof(int)))
// 		printf("%d, ",(result_i[i]));
// 	printf ("\n");
// 	free (result_c);
// 	free (result_i);
// }