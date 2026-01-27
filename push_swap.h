/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wakhazza <wakhazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:26:19 by elarue            #+#    #+#             */
/*   Updated: 2026/01/23 11:39:47 by wakhazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# include "libft.h"
# include "ft_printf.h"


typedef enum e_strategy
{
	STRAT_NONE,
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

int     parse_flags(int ac, char **av, t_config *config);
int     parse_numbers(int i, int ac, char **av, t_node **a);
void    print_stack(t_node *a, t_config *config);

void    sa(t_node **stack_a);
void    sb(t_node **stack_b);
void    ss(t_node **stack_a, t_node **stack_b);
void    pa(t_node **stack_a, t_node **stack_b);
void    pb(t_node **stack_a, t_node **stack_b);
void    ra(t_node **stack_a);
void    rb(t_node **stack_b);
void    rr(t_node **stack_a, t_node **stack_b);
void    rra(t_node **stack_a);
void    rrb(t_node **stack_b);
void    rrr(t_node **stack_a, t_node **stack_b);
t_node	*node_new(int value);

int     find_min_pos(t_node *stack);
void    min_to_top(t_node **stack_a, int min_pos);
void    insertion_sort(t_node **stack_a, t_node **stack_b);

#endif