/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wakhazza <wakhazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 10:24:35 by elarue            #+#    #+#             */
/*   Updated: 2026/01/23 15:05:50 by wakhazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	parse_flags(int ac, char **av, t_config *config)
{
	int	i;

	i = 1;
	while (i < ac && av[i][0] == '-' && av[i][1] == '-')
	{
		if (!ft_strncmp(av[i], "--simple", 9)
			&& config->strat == STRAT_NONE)
			config->strat = STRAT_SIMPLE;
		else if (!ft_strncmp(av[i], "--medium", 9)
			&& config->strat == STRAT_NONE)
			config->strat = STRAT_MEDIUM;
		else if (!ft_strncmp(av[i], "--complex", 10)
			&& config->strat == STRAT_NONE)
			config->strat = STRAT_COMPLEX;
		else if (!ft_strncmp(av[i], "--adaptive", 11)
			&& config->strat == STRAT_NONE)
			config->strat = STRAT_ADAPTIVE;
		else if (!ft_strncmp(av[i], "--bench", 7) && config->bench == 0)
			config->bench = 1;
		else
			return (-1);
		i++;
	}
	return (i);
}
