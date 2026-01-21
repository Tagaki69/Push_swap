/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:14:48 by elarue            #+#    #+#             */
/*   Updated: 2025/11/26 10:24:21 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;

	current = *lst;
	if (*lst == 0 || del == 0)
		return ;
	while (*lst != NULL)
	{
		current = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(current, del);
	}
}
/*
#include <stdio.h>

void	del_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *list = NULL;
	
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("Premier")));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("Deuxieme")));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("Troisieme")));
	printf("Avant suppression:\n");
	printf("Taille de la liste: %d\n", ft_lstsize(list));
	ft_lstclear(&list, del_content);
	printf("Apres ft_lstclear:\n");
	if (list == NULL)
		printf("Taille de la liste: %d\n", ft_lstsize(list));
	else
		printf("Erreur: liste non videe\n");
	return (0);
}
*/