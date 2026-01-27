/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wakhazza <wakhazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:58:06 by wakhazza          #+#    #+#             */
/*   Updated: 2026/01/23 14:58:26 by wakhazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_node **src, t_node **dst)
{
	t_node	*tmp;

	if (!src || !(*src))
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}
