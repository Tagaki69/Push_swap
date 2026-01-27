/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wakhazza <wakhazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:59:08 by wakhazza          #+#    #+#             */
/*   Updated: 2026/01/23 15:06:21 by wakhazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

double	compute_disorder(t_node	*a)
{
	double	mistakes;
	double	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	while (a->next)
	{
		if (a->value > a->next->value)
			mistakes += 1;
		total_pairs += 1;
		a = a->next;
	}
	return (mistakes / total_pairs);
}

int	is_sorted(t_node *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int	cleanup_error(t_node **stack)
{
	if (stack)
		free_stack(stack);
	write(2, "Error\n", 6);
	return (1);
}

int	main(int ac, char **av)
{
	t_node		*a;
	t_node		*b;
	t_config	config;
	int			start;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	config.strat = STRAT_NONE;
	config.bench = 0;
	start = parse_flags(ac, av, &config);
	if (start < 0)
		return (cleanup_error(&a));
	if (config.strat == STRAT_NONE)
		config.strat = STRAT_ADAPTIVE;
	if (!parse_numbers(start, ac, av, &a))
		return (cleanup_error(&a));
	if (is_sorted(a))
		return (0);
	printf("%.2f\n", compute_disorder(a));
	insertion_sort(&a, &b);
	print_stack(a, &config);
	free_stack(&a);
	return (0);
}
