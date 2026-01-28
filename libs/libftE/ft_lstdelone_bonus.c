/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:40:13 by elarue            #+#    #+#             */
/*   Updated: 2025/11/26 10:19:01 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
#include <stdio.h>

void	del_content(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *node;

	node = ft_lstnew(ft_strdup("Test node"));
	printf("Avant suppression:\n");
	printf("Content: %s\n", (char *)node->content);
	ft_lstdelone(node, del_content);
	printf("Content: %s\n", (char *)node->content);
	return (0);
}
*/