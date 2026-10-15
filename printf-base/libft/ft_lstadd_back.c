/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 16:00:52 by atardy            #+#    #+#             */
/*   Updated: 2026/10/10 16:01:21 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list			*last;

	if (!lst || !new)
		return ;
	if (*lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

// int	main(void)
// {
// 	t_list	**lst;
// 	char	**content;
// 	t_list	*new;
// 	t_list	*next_address;
// 	char	*str_res;
// 	int		i;
// 	int		n_struct;

// 	i = -1;
// 	n_struct = 5; // max 10 pour des contents propres
// 	content = malloc (sizeof(char*) * (n_struct + 3));
// 	while (++i < n_struct)
// 	{
// 		content[i] = malloc(sizeof(char) * 13);
// 		ft_strlcpy(&content[i][0], "Struct 0 OK", 13);
// 		content[i][7] = (i + 48);
// 	}
// 	lst = malloc(sizeof(t_list*));
// 	new = ft_lstnew(content[0]);
// 	lst[0] = new;
// 	i = 0;
// 	str_res = new->content;
// 		printf ("node %d cree, content : %s \n", i, str_res);
// 	while (++i < n_struct)
// 	{
// 		new->next = ft_lstnew(content[i]);
// 		new = new->next;
// 		str_res = new->content;
// 		printf ("node %d cree, content : %s \n", i, str_res);
// 	}
// 	printf ("\n");
// 	//----
// 	content[n_struct] = "nouveau";
// 	new = ft_lstnew(content[n_struct]);
// 	ft_lstadd_back(lst, new);
// 	content[n_struct + 1] = "Re-nouveau";
// 	new = ft_lstnew(content[n_struct + 1]);
// 	ft_lstadd_back(lst, new);
// 	content[n_struct + 2] = "RE-Re-nouveau";
// 	new = ft_lstnew(content[n_struct + 2]);
// 	ft_lstadd_back(lst, new);
// 	new = lst[0];
// 	printf ("Contenus apres : \n");
// 	while (new)
// 	{
// 		str_res = new->content;
// 		printf ("%s\n", str_res);
// 		new = new->next;
// 	}
// 	//----
// 	i = -1;
// 	new = lst[0];
// 	while (++i < n_struct)
// 	{
// 		next_address = new->next;
// 		free (content[i]);	
// 		free (new);
// 		new = next_address;
// 	}
// 	free (lst);
// 	free (content);
// 	}