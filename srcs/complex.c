/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:07:00 by enzolarue         #+#    #+#             */
/*   Updated: 2026/01/28 11:00:13 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	bubble_sort(int *sorted, int size)
{
	int	i;
	int	swapped;
	int	tmp;

	swapped = 0;
	while (swapped == 0)
	{
		swapped = 1;
		i = 0;
		while (i < size - 1)
		{
			if (sorted[i] > sorted[i + 1])
			{
				tmp = sorted[i];
				sorted[i] = sorted[i + 1];
				sorted[i + 1] = tmp;
				swapped = 0;
			}
			i++;
		}
	}
}

void	replace_values_by_index(t_node *a, int *sorted, int size)
{
	t_node	*tmp;
	int		i;

	tmp = a;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (sorted[i] == tmp->value)
			{
				tmp->value = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
}

void	compress_stack_to_index(t_node *a)
{
	int		size;
	int		*sorted;
	int		i;
	t_node	*tmp;

	size = stack_size(a);
	sorted = malloc(sizeof(int) * size);
	if (!sorted)
	{
		free(sorted);
		return ;
	}
	tmp = a;
	i = 0;
	while (tmp)
	{
		sorted[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	bubble_sort(sorted, size);
	replace_values_by_index(a, sorted, size);
	free(sorted);
}

int	get_max_bits(t_node *a)
{
	int		max;
	t_node	*tmp;
	int		bits;

	if (a == NULL)
		return (0);
	tmp = a;
	bits = 0;
	max = tmp->value;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_node **a, t_node **b, t_config *config)
{
	int	max_bits;
	int	bit;
	int	size;
	int	i;

	max_bits = get_max_bits(*a);
	bit = 0;
	while (bit < max_bits)
	{
		size = stack_size(*a);
		i = 0;
		while (i < size)
		{
			if (((*a)->value >> bit) & 1)
				ra(a, config);
			else
				pb(a, b, config);
			i++;
		}
		while (*b)
			pa(a, b, config);
		bit++;
	}
}
