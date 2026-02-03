/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wakhazza <wakhazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 13:10:04 by wakhazza          #+#    #+#             */
/*   Updated: 2026/02/02 11:32:29 by wakhazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line.h"

void	error_and_exit(t_node **a, t_node **b, char *line)
{
	if (line)
		free(line);
	if (a && *a)
		free_stack(a);
	if (b && *b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

int	sorted(t_node *a)
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

void	execute_moves(char *line, t_node **a, t_node **b)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		chk_sa(a);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		chk_sb(b);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		chk_ss(a, b);
	else if (ft_strncmp(line, "pa\n", 4) == 0)
		chk_pa(a, b);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		chk_pb(a, b);
	else if (ft_strncmp(line, "ra\n", 4) == 0)
		chk_ra(a);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		chk_rb(b);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		chk_rr(a, b);
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		chk_rra(a);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		chk_rrb(b);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		chk_rrr(a, b);
	else
		error_and_exit(a, b, line);
}

void	checker(t_node **a, t_node **b)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		execute_moves(line, a, b);
		free(line);
	}
	if (sorted(*a) && !(*b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_node		*a;
	t_node		*b;
	t_config	config;
	int			i;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	ft_memset(&config, 0, sizeof(t_config));
	i = parse_flags(ac, av, &config);
	if (i == -1)
		error_and_exit(&a, &b, NULL);
	if (!parse_numbers(i, ac, av, &a))
		error_and_exit(&a, &b, NULL);
	checker(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
