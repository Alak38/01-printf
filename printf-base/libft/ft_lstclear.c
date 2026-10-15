/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 16:01:43 by atardy            #+#    #+#             */
/*   Updated: 2026/10/10 16:01:43 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next_address;
	int		i;

	if (!lst || !*lst)
		return ;
	i = 0;
	current = *lst;
	while (current)
	{
		next_address = current->next;
		del (current->content);
		current->next = NULL;
		free (current);
		current = NULL;
		current = next_address;
		i++;
	}
	lst[0] = NULL;
}

// static void	ft_delete(void *target)
// {
// 	free (target);
// }

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
// 	content = malloc (sizeof(char*) * (n_struct));
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
// 	ft_lstclear(lst, ft_delete);
// 	if (lst == NULL)
// 		printf ("lst = NULL : TOTAL ANNIHILATION");
// 	i = -1;
// 	while (++i < n_struct)
// 	{
// 		printf ("Là aussi\n");
// 		if (lst[i])
// 		{
// 			printf ("Là encore\n");
// 			str_res = lst[i]->content;
// 			printf ("lst[%d] : %s \n", i, str_res);
// 			ft_lstdelone (lst[i], ft_delete);
// 			lst[i] = NULL;
// 		}
// 		if (!lst[i])
// 			printf("lst[%d] n'existe plus\n", i);
// 	}
// 	printf ("Là finalement\n");
// 	//----
// 	i = -1;
// 	new = lst[0];
// 	while (++i < n_struct)
// 	{
// 		next_address = new->next;
// 		// free (content[i]);	
// 		// free (new);
// 		new = next_address;
// 	}
// 	// free (lst);
// 	free (content);
// 	}