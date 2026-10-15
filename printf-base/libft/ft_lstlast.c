/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 09:27:34 by atardy            #+#    #+#             */
/*   Updated: 2026/10/10 09:27:48 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// int	main(void)
// {
// 	t_list	**lst;
// 	char	*content[] = {"Struct0 ok", "Struct1 ok", "Struct2 ok"
// 		, "Struct3 ok", "Struct4 ok"};
// 	t_list	*new;
// 	char	*str_res;
// 	int		i;
// 	int		n_struct;

// 	i = -1;
// 	n_struct = 5;
// 	lst = malloc(sizeof(t_list*) * n_struct);
// 	while (++i < n_struct)
// 	{
// 		new = ft_lstnew(content[i]);
// 		lst[i] = new;
// 		if (lst[i-1])
// 			lst[i-1]->next = new;
// 		str_res = lst[i]->content;
// 		printf ("lst[%d] : %s \n", i, str_res);
// 	}
// 	printf ("\n");
// 	new = ft_lstlast(*lst);
// 	str_res = new->content;
// 	printf ("contenu de la dernière struct : %s\n", str_res);
// 	i = -1;
// 	while (++i <n_struct)
// 		free (lst[i]);
// 	free (lst);
// }