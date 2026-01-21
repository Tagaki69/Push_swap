/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 11:04:42 by elarue            #+#    #+#             */
/*   Updated: 2025/11/26 14:17:51 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*current;

	count = 0;
	current = lst;
	while (current != NULL)
	{
		current = current->next;
		count++;
	}
	return (count);
}
/*
#include <stdio.h>
int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;

	node1 = ft_lstnew("Premier");
	node2 = ft_lstnew("Deuxième");
	node3 = ft_lstnew("Troisième");
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	printf("Taille de la liste: %d\n", ft_lstsize(node1));
	free(node1);
	free(node2);
	free(node3);
	return (0);
}
*/