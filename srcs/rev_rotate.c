/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wakhazza <wakhazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:58:09 by wakhazza          #+#    #+#             */
/*   Updated: 2026/01/27 16:09:14 by wakhazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rev_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*st_last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = *stack;
	st_last = NULL;
	while (last->next)
	{
		st_last = last;
		last = last->next;
	}
	st_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_node **stack_a, t_config *config)
{
	rev_rotate(stack_a);
	ft_printf("rra\n");
	if (config->bench)
	{
		config->counts[COUNT_RRA]++;
		config->total++;
	}
}

void	rrb(t_node **stack_b, t_config *config)
{
	rev_rotate(stack_b);
	ft_printf("rrb\n");
	if (config->bench)
	{
		config->counts[COUNT_RRB]++;
		config->total++;
	}
}

void	rrr(t_node **stack_a, t_node **stack_b, t_config *config)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_printf("rrr\n");
	if (config->bench)
	{
		config->counts[COUNT_RRR]++;
		config->total++;
	}
}
