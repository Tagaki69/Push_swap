/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:56:06 by elarue            #+#    #+#             */
/*   Updated: 2025/11/26 14:38:23 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	if (current == NULL)
		return (NULL);
	if (current-> next == NULL)
		return (current);
	while (current->next != NULL)
		current = current->next;
	return (current);
}
/*
#include <stdio.h>
int	main(void)
{
	t_list	*lst;
	t_list	*current;
	int	i;

	i = 0;
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("Premier")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("Deuxieme")));
	ft_lstadd_back(&lst, ft_lstnew(ft_strdup("Troisieme")));
	current = lst;
	while (lst)
	{
		printf("node %s\n", (char *)lst->content);
		lst= lst->next;
	}
	printf("Dernier node: %s\n", (char *)ft_lstlast(current)->content);
	return (0);
}

*/