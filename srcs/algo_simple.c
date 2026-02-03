/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wakhazza <wakhazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:00:31 by wakhazza          #+#    #+#             */
/*   Updated: 2026/01/28 14:15:48 by wakhazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

double	compute_disorder(t_node	*a)
{
	double	mistakes;
	double	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	if (!a || !a->next)
		return (0.0);
	while (a->next)
	{
		if (a->value > a->next->value)
			mistakes += 1;
		total_pairs += 1;
		a = a->next;
	}
	return (mistakes / total_pairs);
}

int	is_sorted(t_node *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	find_min_pos(t_node *stack)
{
	t_node	*tmp;
	int		min;
	int		min_pos;
	int		i;

	tmp = stack;
	min = tmp->value;
	min_pos = 0;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->value < min)
		{
			min = tmp->value;
			min_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min_pos);
}

void	min_to_top(t_node **stack_a, int min_pos, t_config *config)
{
	int	size;
	int	moves;

	size = stack_size(*stack_a);
	if (min_pos == 0)
		return ;
	if (min_pos == 1)
		return (sa(stack_a, config));
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(stack_a, config);
			min_pos--;
		}
	}
	else
	{
		moves = size - min_pos;
		while (moves > 0)
		{
			rra(stack_a, config);
			moves--;
		}
	}
}

void	insertion_sort(t_node **stack_a, t_node **stack_b, t_config *config)
{
	int		min_pos;

	while (stack_size(*stack_a) > 0)
	{
		min_pos = find_min_pos(*stack_a);
		min_to_top(stack_a, min_pos, config);
		pb(stack_a, stack_b, config);
	}
	while (*stack_b)
		pa(stack_a, stack_b, config);
}
