/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:59:08 by wakhazza          #+#    #+#             */
/*   Updated: 2026/02/03 13:07:00 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_node		*a;
	t_node		*b;
	t_config	config;
	int			strat;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	init_config(&config);
	strat = parse_flags(ac, av, &config);
	if (strat < 0)
		return (cleanup_error(&a, 0));
	if (config.strat == STRAT_NONE)
		config.strat = STRAT_ADAPTIVE;
	if (!parse_numbers(strat, ac, av, &a) || !a)
		return (cleanup_error(&a, 0));
	config.disorder = compute_disorder(a);
	if (is_sorted(a) && config.bench == 0)
		return (cleanup_error(&a, 1));
	find_index(&a);
	chose_strat(&config, &a, &b);
	print_bench(&config);
	if (config.count_only)
		ft_printf("\n%d", config.total);
	free_stack(&a);
	return (0);
}
