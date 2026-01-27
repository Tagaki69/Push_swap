/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wakhazza <wakhazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:57:57 by wakhazza          #+#    #+#             */
/*   Updated: 2026/01/23 14:57:58 by wakhazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_node **stack)
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

void	sa(t_node **stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_node **stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
