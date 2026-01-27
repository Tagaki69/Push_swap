/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wakhazza <wakhazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:04:17 by wakhazza          #+#    #+#             */
/*   Updated: 2026/01/23 15:06:47 by wakhazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*node_new(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

int	push_back(t_node **a, int v)
{
	t_node	*new;
	t_node	*last;

	new = node_new(v);
	if (!new)
		return (0);
	if (!*a)
	{
		*a = new;
		return (1);
	}
	last = *a;
	while (last->next)
		last = last->next;
	last->next = new;
	return (1);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	print_stack(t_node *a, t_config *config)
{
	ft_printf("Stack A: ");
	while (a)
	{
		ft_printf("%d ", a->value);
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
