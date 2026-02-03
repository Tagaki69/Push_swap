/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:58:06 by wakhazza          #+#    #+#             */
/*   Updated: 2026/02/03 13:05:43 by elarue           ###   ########.fr       */
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
	if (!config->count_only)
		ft_printf("pb\n");
	if (config->bench || config->count_only)
	{
		config->counts[COUNT_PB]++;
		config->total++;
	}
}

void	pa(t_node **stack_a, t_node **stack_b, t_config *config)
{
	push(stack_b, stack_a);
	if (!config->count_only)
		ft_printf("pa\n");
	if (config->bench || config->count_only)
	{
		config->counts[COUNT_PA]++;
		config->total++;
	}
}
