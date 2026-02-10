/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:58:06 by wakhazza          #+#    #+#             */
/*   Updated: 2026/02/03 13:56:31 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_node **src, t_node **dst)
{
	t_node	*tmp;

	if (!src || !(*src))
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pb(t_node **stack_a, t_node **stack_b, t_config *config)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
	if (config->bench)
	{
		config->counts[COUNT_PB]++;
		config->total++;
	}
}

void	pa(t_node **stack_a, t_node **stack_b, t_config *config)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
	if (config->bench)
	{
		config->counts[COUNT_PA]++;
		config->total++;
	}
}
