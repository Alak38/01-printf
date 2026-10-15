/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 18:13:56 by atardy            #+#    #+#             */
/*   Updated: 2026/10/09 18:14:17 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc (sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

// int	main(void)
// {
// 	int		content[] = {12432, 123, 1, 2, 3, 4};
// 	t_list	*result;
// 	int		*res_int;

// 	result = ft_lstnew(content);
// 	res_int = result->content;
// 	printf ("%d\n", res_int[0]);
// 	free (result);
// 	return (0);
// }
