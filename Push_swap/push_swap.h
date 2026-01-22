/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:26:19 by elarue            #+#    #+#             */
/*   Updated: 2026/01/22 11:10:03 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

long				ft_atoi(const char *str);
char				**ft_split(char const *s, char c);
int					ft_printf(const char *format, ...);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

typedef enum e_strategy
{
	STRAT_ADAPTIVE,
	STRAT_SIMPLE,
	STRAT_MEDIUM,
	STRAT_COMPLEX
}					t_strategy;

typedef struct s_config
{
	t_strategy		strat;
	int				bench;
}					t_config;

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

#endif