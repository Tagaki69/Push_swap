/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wakhazza <wakhazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:29:59 by wakhazza          #+#    #+#             */
/*   Updated: 2026/01/27 16:33:43 by wakhazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	chunk_sort(t_node **stack_a, t_node **stack_b, t_config *config)
{
	int	chunk_size;
	int	i;
	int	size;

	i = 0;
	size = stack_size(*stack_a);
	chunk_size = size / set_chunks(stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			pb(stack_a, stack_b, config);
			rb(stack_b, config);
			i++;
		}
		else if ((*stack_a)->index <= (i + chunk_size))
		{
			pb(stack_a, stack_b, config);
			i++;
		}
		else
			ra(stack_a, config);
	}
	bring_to_a(stack_a, stack_b, config);
}

void	bring_to_a(t_node **stack_a, t_node **stack_b, t_config *config)
{
	int	size;
	int	max_pos;

	size = stack_size(*stack_b);
	while (size != 0)
	{
		max_pos = find_max_pos(*stack_b);
		max_to_top(stack_b, max_pos, config);
		pa(stack_a, stack_b, config);
		size--;
	}
}

int	find_max_pos(t_node *stack)
{
	t_node	*tmp;
	int		max;
	int		max_pos;
	int		i;

	tmp = stack;
	max = tmp->index;
	max_pos = 0;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->index > max)
		{
			max = tmp->index;
			max_pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (max_pos);
}

void	max_to_top(t_node **stack_b, int max_pos, t_config *config)
{
	int	size;
	int	moves;

	size = stack_size(*stack_b);
	if (max_pos == 0)
		return ;
	if (max_pos == 1)
		return (sb(stack_b, config));
	if (max_pos <= size / 2)
	{
		while (max_pos > 0)
		{
			rb(stack_b, config);
			max_pos--;
		}
	}
	else
	{
		moves = size - max_pos;
		while (moves > 0)
		{
			rrb(stack_b, config);
			moves--;
		}
	}
}

int	set_chunks(t_node **stack_a)
{
	int	size;
	int	chunks;

	size = stack_size(*stack_a);
	chunks = find_sqrt(size);
	if (chunks == 0)
		return (1);
	return (chunks);
}
