/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 17:53:18 by atardy            #+#    #+#             */
/*   Updated: 2026/10/09 19:37:04 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// int	main(void)
// {
// 	t_list	**lst;
// 	char	*content[] = {"Struct créée", "Struct2 créée"
// 			, "Struct3 créée", "Struct4 créée"};
// 	t_list	*new;
// 	char	*str_res;
// 	int		i;
// 	//int		next_null;

// 	i = -1;
// 	lst = malloc(sizeof(t_list*) * 5);
// 	while (++i < 4)
// 	{
// 		new = ft_lstnew(content[i]);
// 		lst[i] = new;
// 		if (lst[i-1])
// 			lst[i-1]->next = new;
// 		str_res = lst[i]->content;
// 		printf ("lst[%d] : %s \n", i, str_res);
// 	}
// 	i = -1;
// 	// while (++i < 4)
// 	// {
// 	// 	if (lst[i]->next == NULL)
// 	// 		next_null = 1;
// 	// 	else 
// 	// 		next_null = 0;
// 	// 	// printf ("\nlst[%d] : Next est vide : %d", i, next_null);
// 	// }
// 	printf ("\n");
// 	printf ("Nb de t_list : %d\n", ft_lstsize(lst[0]));
// 	i = -1;
// 	// while (++i < 4)
// 	// {
// 	// 	str_res = lst[i]->content;
// 	// 	// printf ("lst[%d] : %s \n", i, str_res);
// 	// }
// }