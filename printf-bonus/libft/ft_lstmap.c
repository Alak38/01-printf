/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardy <atardy@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 16:48:03 by atardy            #+#    #+#             */
/*   Updated: 2026/10/10 16:48:06 by atardy           ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cpy(t_list *lst, t_list *cpy
		, void *(*f)(void *), void (*del)(void *))
{
	int		n_success;
	void	*f_cont;

	n_success = 1;
	while (lst)
	{
		f_cont = f(lst->content);
		if (f_cont == NULL)
			return (n_success);
		cpy->next = ft_lstnew(f_cont);
		if (cpy->next == NULL)
		{
			del (f_cont);
			return (n_success);
		}
		cpy = cpy->next;
		lst = lst->next;
		n_success++;
	}
	return (0);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	void	*f_cont;

	if (!lst || !f)
		return (NULL);
	f_cont = f(lst->content);
	if (f_cont == NULL)
		return (NULL);
	head = ft_lstnew(f_cont);
	if (head == NULL)
		return (NULL);
	if (lst->next)
		if (cpy(lst->next, head, f, del) != 0)
			ft_lstclear (&head, del);
	return (head);
}

// static void	*str_toupper(void *s)
// {
// 	int		i;
// 	char	*str;
// 	char	*cpy;

// 	i = ft_strlen((char*)s);
// 	cpy = malloc(sizeof(char) * i + 1);
// 	if (cpy == NULL)
// 		return (NULL);
// 	i = -1;
// 	str = (char*)s;
// 	while (str[++i])
// 	{
// 		if (str[i] >= 97 && str[i] <= 122)
// 			cpy[i] = str[i] - 32;
// 		else
// 			cpy[i] = str[i];
// 	}
// 	return (cpy);
// }

// static void	ft_delete(void *target)
// {
// 	free (target);
// 	target = NULL;
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
// 	new = ft_lstmap(lst[0], str_toupper, ft_delete);
// 	if (new == NULL)
// 	{
// 		printf ("retour de lstmap == NULL\n");
// 		return (-1);	
// 	}
// 	i = -1;
// 	while (++i < n_struct)
// 	{
// 		str_res = new->content;
// 		printf ("new%d : %s \n", i, str_res);
// 		new = new->next;
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