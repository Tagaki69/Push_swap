/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:02:39 by elarue            #+#    #+#             */
/*   Updated: 2025/11/26 14:17:48 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	t_list	*node1;

	if (argc == 2)
	{
		node1 = ft_lstnew(argv[1]);
		if (node1)
		{
			printf("Content: %s\n", (char *)node1->content);
			printf("Next: %p\n", node1->next);
		}
	}
	return (0);
}
*/