/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_swap_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wakhazza <wakhazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:37:51 by wakhazza          #+#    #+#             */
/*   Updated: 2026/01/29 16:47:38 by wakhazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	chk_sa(t_node **stack_a)
{
	swap(stack_a);
}

void	chk_sb(t_node **stack_b)
{
	swap(stack_b);
}

void	chk_ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void	chk_pa(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, stack_a);
}

void	chk_pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_a, stack_b);
}
