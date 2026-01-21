/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 12:31:25 by elarue            #+#    #+#             */
/*   Updated: 2025/11/26 14:17:02 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*liste;
	t_list	*current;

	liste = NULL;
	node1 = ft_lstnew("Premier");
	node2 = ft_lstnew("Deuxième");
	node3 = ft_lstnew("Troisième");
	ft_lstadd_front(&liste, node2);
	ft_lstadd_front(&liste, node3);
	ft_lstadd_front(&liste, node1);
	current = liste;
	while (current)
	{
		printf("%s -> ", (char *)current->content);
		current = current->next;
	}
	return (0);
}
*/
