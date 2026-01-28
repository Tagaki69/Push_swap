/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wakhazza <wakhazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:58:14 by wakhazza          #+#    #+#             */
/*   Updated: 2026/01/27 16:09:41 by wakhazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
}

void	ra(t_node **stack_a, t_config *config)
{
	rotate(stack_a);
	ft_printf ("ra\n");
	if (config->bench)
	{
		config->counts[COUNT_RA]++;
		config->total++;
	}
}

void	rb(t_node **stack_b, t_config *config)
{
	rotate(stack_b);
	ft_printf ("rb\n");
	if (config->bench)
	{
		config->counts[COUNT_RB]++;
		config->total++;
	}
}

void	rr(t_node **stack_a, t_node **stack_b, t_config *config)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
	if (config->bench)
	{
		config->counts[COUNT_RR]++;
		config->total++;
	}
}
