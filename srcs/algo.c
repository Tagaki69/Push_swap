/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wakhazza <wakhazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:00:31 by wakhazza          #+#    #+#             */
/*   Updated: 2026/01/23 15:01:23 by wakhazza         ###   ########.fr       */
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

void	min_to_top(t_node **stack_a, int min_pos)
{
	int	size;
	int	moves;

	size = stack_size(*stack_a);
	if (min_pos == 0)
		return ;
	if (min_pos == 1)
		return (sa(stack_a));
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra(stack_a);
			min_pos--;
		}
	}
	else
	{
		moves = size - min_pos;
		while (moves > 0)
		{
			rra(stack_a);
			moves--;
		}
	}
}

void	insertion_sort(t_node **stack_a, t_node **stack_b)
{
	int		min_pos;

	while (stack_size(*stack_a) > 0)
	{
		min_pos = find_min_pos(*stack_a);
		min_to_top(stack_a, min_pos);
		pb(stack_a, stack_b);
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}
