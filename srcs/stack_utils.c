/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wakhazza <wakhazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:04:17 by wakhazza          #+#    #+#             */
/*   Updated: 2026/01/27 15:15:55 by wakhazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_size(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

int	find_index(t_node **stack_a)
{
	t_node	*tmp;
	t_node	*current;
	int		smaller;
	int		total;

	total = 0;
	current = *stack_a;
	while (current != NULL)
	{
		smaller = 0;
		tmp = *stack_a;
		while (tmp != NULL)
		{
			if (current->value > tmp ->value)
				smaller += 1;
			tmp = tmp->next;
		}
		current->index = smaller;
		current = current->next;
		total++;
	}
	return (total);
}

int	find_sqrt(int total)
{
	int	i;

	i = 1;
	if (total < 0)
		return (0);
	while (i * i < total)
	{
		if (i * i == total)
			return (i);
		i++;
	}
	return (i - 1);
}

t_node	*node_new(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

int	push_back(t_node **a, int v)
{
	t_node	*new;
	t_node	*last;

	new = node_new(v);
	if (!new)
		return (0);
	if (!*a)
	{
		*a = new;
		return (1);
	}
	last = *a;
	while (last->next)
		last = last->next;
	last->next = new;
	return (1);
}
