/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 16:03:20 by atardy            #+#    #+#             */
/*   Updated: 2026/10/10 16:03:20 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del (lst->content);
	free (lst);
}

// int	main(void)
// {
// 	t_list	**lst;
// 	char	**content;
// 	t_list	*new;
// 	char	*str_res;
// 	int		i;
// 	int		n_struct;

// 	i = -1;
// 	n_struct = 5; // max 10 pour des contents propres
// 	content = malloc (sizeof(char*) * (n_struct));
// 	while (++i < n_struct)
// 	{
// 		content[i] = malloc(sizeof(char) * 13);
// 		ft_strlcpy(&content[i][0], "Struct 0 OK", 13);
// 		content[i][7] = (i + 48);
// 	}
// 	lst = malloc(sizeof(t_list*) * n_struct + 1);
// 	i = -1;
// 	while (++i < n_struct)
// 	{
// 		new = ft_lstnew(content[i]);
// 		lst[i] = new;
// 		if (i > 0)
// 			lst[i-1]->next = new;
// 		str_res = lst[i]->content;
// 		printf ("lst[%d] : %s \n", i, str_res);
// 	}
// 	printf ("Structs créées\n");
// 	//----
// 	new = lst[3]->next;
// 	ft_lstdelone(lst[3], free);
// 	lst[2]->next = new;
// 	i = 0;
// 	new = lst[0];
// 	while (new)
// 	{
// 		if (new->content)
// 		{
// 			printf ("if\n");
// 			str_res = new->content;
// 			printf("lst[%d]->content = %s\n", i, str_res);
// 		}
// 		else
// 			printf ("lst[%d]->content n'existe pas\n", i);
// 		if (new->next)
// 			new = new->next;
// 		i++;
// 	}
// 	//----
// 	i = -1;
// 	while (++i < n_struct)
// 	{
// if (i != 3)
// 	free (content[i]);	
// 		free (lst[i]);
// 	}
// 	free (lst);
// 	free (content);
// }