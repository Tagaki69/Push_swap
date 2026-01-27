/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wakhazza <wakhazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:58:14 by wakhazza          #+#    #+#             */
/*   Updated: 2026/01/23 14:58:35 by wakhazza         ###   ########.fr       */
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

void	ra(t_node **stack_a)
{
	rotate(stack_a);
	ft_printf ("ra\n");
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	ft_printf ("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
