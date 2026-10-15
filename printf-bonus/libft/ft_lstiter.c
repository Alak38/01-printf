/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/23 15:48:45 by atardy            #+#    #+#             */
/*   Updated: 2026/09/23 15:48:45 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	int	size;

	if (!lst || !f)
		return ;
	size = ft_lstsize(lst);
	while (--size >= 0)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// static void	str_toupper(void *s)
// {
// 	int		i;
// 	char	*str;

// 	str = (char*)s;
// 	i = -1;
// 	while (str[++i])
// 		if (str[i] >= 97 && str[i] <= 122)
// 			str[i] = str[i] - 32;
// }

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
// 	printf ("\n");
// 	//----
// 	ft_lstiter(lst[0], str_toupper);
// 	i = -1;
// 	while (++i < n_struct)
// 	{
// 		str_res = lst[i]->content;
// 		printf ("lst[%d] : %s \n", i, str_res);
// 	}
// 	//----
// 	i = -1;
// 	while (++i < n_struct)
// 	{
// 		free (content[i]);	
// 		free (lst[i]);
// 	}
// 	free (lst);
// 	free (content);
// }