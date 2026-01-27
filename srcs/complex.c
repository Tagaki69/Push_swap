/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzolarue <enzolarue@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:07:00 by enzolarue         #+#    #+#             */
/*   Updated: 2026/01/26 18:31:00 by enzolarue        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_size(t_node *lst)
{
	int		count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	compress_stack_to_index(t_node *a)
{
	int 	size_a;
	int	*vals;
	int	*sorted;
	int	i;

	i = 0;
	size_a = stack_size(a);
	vals = malloc(size_a * sizeof(int));
	sorted = malloc(size_a * sizeof(int));
	if (!vals || !sorted)
		return NULL;
	while (a)
	
	
	
}