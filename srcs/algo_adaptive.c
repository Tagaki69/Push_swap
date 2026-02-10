/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 11:27:52 by wakhazza          #+#    #+#             */
/*   Updated: 2026/02/03 13:51:05 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	chose_strat(t_config *config, t_node **stack_a, t_node **stack_b)
{
	if (is_sorted(*stack_a))
		return ;
	if (config->strat == STRAT_ADAPTIVE)
		adaptive_strat(stack_a, stack_b, config);
	else if (config->strat == STRAT_SIMPLE)
		selection_sort(stack_a, stack_b, config);
	else if (config->strat == STRAT_MEDIUM)
		chunk_sort(stack_a, stack_b, config);
	else if (config->strat == STRAT_COMPLEX)
	{
		compress_stack_to_index(*stack_a);
		radix_sort(stack_a, stack_b, config);
	}
}

void	adaptive_strat(t_node **stack_a, t_node **stack_b, t_config *config)
{
	if (config->disorder < 0.2)
	{
		config->chosen = 1;
		selection_sort(stack_a, stack_b, config);
	}
	if (config->disorder >= 0.2 && config->disorder < 0.5)
	{
		config->chosen = 2;
		chunk_sort(stack_a, stack_b, config);
	}
	if (config->disorder >= 0.5)
	{
		config->chosen = 3;
		compress_stack_to_index(*stack_a);
		radix_sort(stack_a, stack_b, config);
	}
}
