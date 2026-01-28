/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:04:03 by elarue            #+#    #+#             */
/*   Updated: 2025/11/26 10:47:19 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	link_chain(t_list *new, t_list **first, t_list **last)
{
	if (*first == NULL)
	{
		*first = new;
		*last = new;
	}
	else
	{
		(*last)->next = new;
		*last = new;
	}
}

void	*verif(void *transformed_content, t_list *first, void (*del)(void *))
{
	if (transformed_content)
		del(transformed_content);
	ft_lstclear(&first, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	void	*transformed_content;
	t_list	*first;
	t_list	*last;

	first = NULL;
	last = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst != NULL)
	{
		transformed_content = f(lst->content);
		new = ft_lstnew(transformed_content);
		if (!new)
		{
			verif(transformed_content, first, del);
			return (NULL);
		}
		link_chain(new, &first, &last);
		lst = lst->next;
	}
	return (first);
}
/*
#include <stdio.h>

void	*uppercase(void *content)
{
	char	*str;
	int		i;

	str = ft_strdup((char *)content);
	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

void	del_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*lst;
	t_list	*mapped;
	t_list	*temp;
	int		i;

	lst = NULL;
	i = 0;
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("Premier")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("Deuxieme")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("Troisieme")));
	printf("Liste lst:\n");
	temp = lst;
	while (temp)
	{
		printf("Node %d: %s\n", i++, (char *)temp->content);
		temp = temp->next;
	}
	mapped = ft_lstmap(lst, uppercase, del_content);
	printf("\nListe transformee:\n");
	i = 0;
	while (mapped)
	{
		printf("Node %d: %s\n", i++, (char *)mapped->content);
		mapped = mapped->next;
	}
	ft_lstclear(&lst, del_content);
	return (0);
}
*/