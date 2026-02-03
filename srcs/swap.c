/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:57:57 by wakhazza          #+#    #+#             */
/*   Updated: 2026/02/03 13:06:13 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || !(*stack) || !((*stack)->next))
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_node **stack_a, t_config *config)
{
	swap(stack_a);
	if (!config->count_only)
		ft_printf("sa\n");
	if (config->bench || config->count_only)
	{
		config->counts[COUNT_SA]++;
		config->total++;
	}
}

void	sb(t_node **stack_b, t_config *config)
{
	swap(stack_b);
	if (!config->count_only)
		ft_printf("sb\n");
	if (config->bench || config->count_only)
	{
		config->counts[COUNT_SB]++;
		config->total++;
	}
}

void	ss(t_node **stack_a, t_node **stack_b, t_config *config)
{
	swap(stack_a);
	swap(stack_b);
	if (!config->count_only)
		ft_printf("ss\n");
	if (config->bench || config->count_only)
	{
		config->counts[COUNT_SS]++;
		config->total++;
	}
}
