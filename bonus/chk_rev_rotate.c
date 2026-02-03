/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chk_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wakhazza <wakhazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 14:40:09 by wakhazza          #+#    #+#             */
/*   Updated: 2026/01/29 16:47:49 by wakhazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	chk_rra(t_node **stack_a)
{
	rev_rotate(stack_a);
}

void	chk_rrb(t_node **stack_b)
{
	rev_rotate(stack_b);
}

void	chk_rrr(t_node **stack_a, t_node **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}
