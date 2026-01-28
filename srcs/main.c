/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 14:59:08 by wakhazza          #+#    #+#             */
/*   Updated: 2026/01/28 10:55:34 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_node *a, t_config *config)
{
	ft_printf("\nStack A:\n");
	while (a)
	{
		ft_printf("%d\n", a->value);
		a = a->next;
	}
	ft_printf("\n");
	ft_printf("Strategy: ");
	if (config->strat == STRAT_SIMPLE)
		ft_printf("SIMPLE\n");
	else if (config->strat == STRAT_MEDIUM)
		ft_printf("MEDIUM\n");
	else if (config->strat == STRAT_COMPLEX)
		ft_printf("COMPLEX\n");
	else if (config->strat == STRAT_ADAPTIVE)
		ft_printf("ADAPTIVE\n");
	ft_printf("Bench mode: ");
	if (config->bench == 1)
		ft_printf("ON\n");
	if (config->bench == 0)
		ft_printf("OFF\n");
}

void	print_stacks(t_node *a, t_node *b)
{
	ft_printf("\nStack A:\n");
	while (a)
	{
		ft_printf("%d\n", a->value);
		a = a->next;
	}
	ft_printf("\nStack B:\n");
	while (b)
	{
		ft_printf("%d\n", b->value);
		b = b->next;
	}
}

void	chose_strat(t_config config, t_node **stack_a, t_node **stack_b)
{
	if (config.strat == STRAT_ADAPTIVE)
		adaptive_strat(stack_a, stack_b, &config);
	else if (config.strat == STRAT_SIMPLE)
	{
		insertion_sort(stack_a, stack_b, &config);
		// ft_printf("simple");
	}
	else if (config.strat == STRAT_MEDIUM)
	{
		chunk_sort(stack_a, stack_b, &config);
		// ft_printf("medium");
	}
	else if (config.strat == STRAT_COMPLEX)
	{
		compress_stack_to_index(*stack_a);
		radix_sort(stack_a, stack_b, &config);
		// ft_printf("complex");
	}
}

void	adaptive_strat(t_node **stack_a, t_node **stack_b, t_config *config)
{
	double	disorder;

	disorder = compute_disorder(*stack_a);
	if (disorder < 0.2)
	{
		insertion_sort(stack_a, stack_b, config);
		// ft_printf("simple");
	}
	if (disorder >= 0.2 && disorder < 0.5)
	{
		chunk_sort(stack_a, stack_b, config);
		// ft_printf("medium");
	}
	if (disorder >= 0.5)
	{
		compress_stack_to_index(*stack_a);
		radix_sort(stack_a, stack_b, config);
		// ft_printf("complex");
	}
}
void	print_bench(t_config *config)
{
	if (!config->bench)
		return ;
	ft_putnbr_fd(config->total, 2);
	ft_putnbr_fd(config->counts[COUNT_PA], 2);
	ft_putnbr_fd(config->counts[COUNT_PB], 2);
	ft_putnbr_fd(config->counts[COUNT_SA], 2);
	ft_putnbr_fd(config->counts[COUNT_SB], 2);
	ft_putnbr_fd(config->counts[COUNT_SS], 2);
	ft_putnbr_fd(config->counts[COUNT_RA], 2);
	ft_putnbr_fd(config->counts[COUNT_RB], 2);
	ft_putnbr_fd(config->counts[COUNT_RR], 2);
	ft_putnbr_fd(config->counts[COUNT_RRA], 2);
	ft_putnbr_fd(config->counts[COUNT_RRB], 2);
	ft_putnbr_fd(config->counts[COUNT_RRR], 2);
}

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
	config.strat = STRAT_NONE;
	config.bench = 0;
	strat = parse_flags(ac, av, &config);
	if (strat < 0)
		return (cleanup_error(&a, 0));
	if (config.strat == STRAT_NONE)
		config.strat = STRAT_ADAPTIVE;
	if (!parse_numbers(strat, ac, av, &a))
		return (cleanup_error(&a, 0));
	if (is_sorted(a))
		return (cleanup_error(&a, 1)); // changer ca.
	// ft_printf("%.2f\n", compute_disorder(a));
	// insertion_sort(&a, &b);
	find_index(&a);
	// print_stacks(a, b);
	chose_strat(config, &a, &b);
	// chunk_sort(&a, &b);
	// print_stacks(a, b);
	print_bench(&config);
	free_stack(&a);
	return (0);
}
