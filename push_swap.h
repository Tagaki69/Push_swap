/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:26:19 by elarue            #+#    #+#             */
/*   Updated: 2026/02/03 13:55:24 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libs/PrintfE/ft_printf.h"
# include "libs/libftE/libft.h"
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef enum e_move
{
	COUNT_SA,
	COUNT_SB,
	COUNT_SS,
	COUNT_PA,
	COUNT_PB,
	COUNT_RA,
	COUNT_RB,
	COUNT_RR,
	COUNT_RRA,
	COUNT_RRB,
	COUNT_RRR,
	COUNT_MAX,
}					t_move;

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
	int				counts[COUNT_MAX];
	int				total;
	int				chosen;
	double			disorder;
}					t_config;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

int					parse_flags(int ac, char **av, t_config *config);
int					parse_numbers(int i, int ac, char **av, t_node **a);
int					find_index(t_node **stack_a);

void				swap(t_node **stack);
void				push(t_node **src, t_node **dest);
void				rotate(t_node **stack);
void				rev_rotate(t_node **stack);
void				sa(t_node **stack_a, t_config *config);
void				sb(t_node **stack_b, t_config *config);
void				ss(t_node **stack_a, t_node **stack_b, t_config *config);
void				pa(t_node **stack_a, t_node **stack_b, t_config *config);
void				pb(t_node **stack_a, t_node **stack_b, t_config *config);
void				ra(t_node **stack_a, t_config *config);
void				rb(t_node **stack_b, t_config *config);
void				rr(t_node **stack_a, t_node **stack_b, t_config *config);
void				rra(t_node **stack_a, t_config *config);
void				rrb(t_node **stack_b, t_config *config);
void				rrr(t_node **stack_a, t_node **stack_b, t_config *config);

void				chunk_sort(t_node **stack_a, t_node **stack_b,
						t_config *config);
void				bring_to_a(t_node **stack_a, t_node **stack_b,
						t_config *config);
void				max_to_top(t_node **stack_b, int max_pos, t_config *config);
int					set_chunks(t_node **stack_a);

void				selection_sort(t_node **stack_a, t_node **stack_b,
						t_config *config);
void				min_to_top(t_node **stack_a, int min_pos, t_config *config);

t_node				*node_new(int value);
int					push_back(t_node **a, int v);
int					stack_size(t_node *lst);
int					find_min_pos(t_node *stack);
int					find_max_pos(t_node *stack);
int					is_sorted(t_node *a);
int					find_sqrt(int total);
double				compute_disorder(t_node *a);

void				free_stack(t_node **stack);
void				free_split(char **split);
int					cleanup_error(t_node **stack, int j);

void				print_stack(t_node *a, t_config *config);
void				print_stacks(t_node *a, t_node *b);

void				chose_strat(t_config *config, t_node **stack_a,
						t_node **stack_b);
void				adaptive_strat(t_node **stack_a, t_node **stack_b,
						t_config *config);

void				compress_stack_to_index(t_node *a);
void				radix_sort(t_node **a, t_node **b, t_config *config);

void				init_config(t_config *config);
void				print_bench(t_config *config);

void				chk_sa(t_node **stack_a);
void				chk_sb(t_node **stack_b);
void				chk_ss(t_node **stack_a, t_node **stack_b);
void				chk_pa(t_node **stack_a, t_node **stack_b);
void				chk_pb(t_node **stack_a, t_node **stack_b);

void				chk_ra(t_node **stack_a);
void				chk_rb(t_node **stack_b);
void				chk_rr(t_node **stack_a, t_node **stack_b);

void				chk_rra(t_node **stack_a);
void				chk_rrb(t_node **stack_b);
void				chk_rrr(t_node **stack_a, t_node **stack_b);

#endif