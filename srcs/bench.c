/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 12:59:07 by wakhazza          #+#    #+#             */
/*   Updated: 2026/02/03 13:55:52 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_config(t_config *config)
{
	int	i;

	config->strat = STRAT_NONE;
	config->bench = 0;
	config->total = 0;
	config->disorder = 0;
	config->chosen = 0;
	i = 0;
	while (i < COUNT_MAX)
	{
		config->counts[i] = 0;
		i++;
	}
}

void	put_move_name(int i)
{
	if (i == COUNT_SA)
		ft_putstr_fd(" sa: ", 2);
	else if (i == COUNT_SB)
		ft_putstr_fd(" sb: ", 2);
	else if (i == COUNT_SS)
		ft_putstr_fd(" ss: ", 2);
	else if (i == COUNT_PA)
		ft_putstr_fd(" pa: ", 2);
	else if (i == COUNT_PB)
		ft_putstr_fd(" pb: ", 2);
	else if (i == COUNT_RA)
		ft_putstr_fd(" ra: ", 2);
	else if (i == COUNT_RB)
		ft_putstr_fd(" rb: ", 2);
	else if (i == COUNT_RR)
		ft_putstr_fd(" rr: ", 2);
	else if (i == COUNT_RRA)
		ft_putstr_fd(" rra: ", 2);
	else if (i == COUNT_RRB)
		ft_putstr_fd(" rrb: ", 2);
	else if (i == COUNT_RRR)
		ft_putstr_fd(" rrr: ", 2);
}

void	put_disorder_strategy(t_config *config)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_printf("%.2f", config->disorder * 100);
	ft_putchar_fd('%', 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	if (config->strat == STRAT_SIMPLE)
		ft_putstr_fd(" Simple / O(n2)", 2);
	if (config->strat == STRAT_MEDIUM)
		ft_putstr_fd(" Medium / O(n√n)", 2);
	if (config->strat == STRAT_COMPLEX)
		ft_putstr_fd(" Complex / O(n log n)", 2);
	if (config->strat == STRAT_ADAPTIVE)
		ft_putstr_fd(" Adaptive / ", 2);
	if (config->chosen == 1)
		ft_putstr_fd(" O(n2)", 2);
	if (config->chosen == 2)
		ft_putstr_fd(" O(n√n)", 2);
	if (config->chosen == 3)
		ft_putstr_fd(" O(n log n)", 2);
	ft_putstr_fd("\n", 2);
}

void	print_bench(t_config *config)
{
	int		i;

	if (!config->bench)
		return ;
	put_disorder_strategy(config);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(config->total, 2);
	ft_putstr_fd("\n", 2);
	i = 0;
	ft_putstr_fd("[bench]", 2);
	while (i < COUNT_MAX)
	{
		if (i == COUNT_MAX / 2)
		{
			ft_putstr_fd("\n", 2);
			ft_putstr_fd("[bench]", 2);
		}
		put_move_name(i);
		ft_putnbr_fd(config->counts[i], 2);
		i++;
	}
}
