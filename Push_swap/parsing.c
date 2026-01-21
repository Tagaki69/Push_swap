/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:24:35 by elarue            #+#    #+#             */
/*   Updated: 2026/01/21 14:35:34 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	is_only_spaces(char *s)
{
	int	i;

	if (!s)
		return (1);
	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	parse_int_strict(char *s, int *out)
{
	int		i;
	long	n;

	i = 0;
	if (!s || !out)
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (s[i] == '\0' || s[i] < '0' || s[i] > '9')
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	n = ft_atoi(s);
	if (n < -2147483647 - 1 || n > 2147483647)
		return (0);
	*out = (int)n;
	return (1);
}

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

int	has_duplicate(t_node *a, int v)
{
	while (a)
	{
		if (a->value == v)
			return (1);
		a = a->next;
	}
	return (0);
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

int	parse_numbers(int i, int ac, char **av, t_node **a)
{
	char	**split;
	char	**tmp;
	int		value;

	while (i < ac)
	{
		if (is_only_spaces(av[i]))
			return (0);
		tmp = ft_split(av[i++], ' ');
		if (!tmp)
			return (0);
		split = tmp;
		while (*split)
		{
			if (!parse_int_strict(*split, &value) || has_duplicate(*a, value)
				|| !push_back(a, value))
				return (free_split(tmp), 0);
			split++;
		}
		free_split(tmp);
	}
	return (1);
}

static void	print_stack(t_node *a)
{
	while (a)
	{
		ft_printf("%d ", a->value);
		a = a->next;
	}
	ft_printf("\n");
}

int	main(int ac, char **av)
{
	t_node	*a;
	int		start;

	a = NULL;
	start = 1;
	if (ac < 2)
		return (0);
	if (!parse_numbers(start, ac, av, &a))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	print_stack(a);
	return (0);
}