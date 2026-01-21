/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 09:35:40 by elarue            #+#    #+#             */
/*   Updated: 2025/11/26 15:15:07 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	current = lst;
	if (lst == 0 || f == 0)
		return ;
	while (current != NULL)
	{
		f(current->content);
		current = current->next;
	}
}

/*
#include <stdio.h>

void	uppercase_first(void *content)
{
	char	*str;

	str = (char *)content;
	if (str && str[0] >= 'a' && str[0] <= 'z')
		str[0] = str[0] - 32;
}

int	main(void)
{
	char str1[] = "hello";
	char str2[] = "world";

	t_list *node1 = ft_lstnew(str1);
	t_list *node2 = ft_lstnew(str2);
	node1->next = node2;
	node2->next = NULL;
	printf("Avant: %s, %s\n", (char *)node1->content, (char *)node2->content);
	ft_lstiter(node1, uppercase_first);
	printf("Après: %s, %s\n", (char *)node1->content, (char *)node2->content);
	free(node1);
	free(node2);
	return (0);
}
*/