/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 20:48:08 by edmvarda          #+#    #+#             */
/*   Updated: 2026/04/21 23:24:14 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <limits.h>

/* operations benchmark struct */
typedef struct s_bench
{
	unsigned int	sa;
	unsigned int	sb;
	unsigned int	ss;
	unsigned int	pa;
	unsigned int	pb;
	unsigned int	ra;
	unsigned int	rb;
	unsigned int	rr;
	unsigned int	rra;
	unsigned int	rrb;
	unsigned int	rrr;
}					t_bench;

/* flags for sorting strategy */
typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}					t_strategy;

/* parsing flags */
typedef struct s_flags
{
	t_strategy		cmd;
	int				bench;
	int				arg_i;
}					t_flags;

/* main functions */
void				sa(t_list **a, int print);
void				sb(t_list **b, int print);
void				ss(t_list **a, t_list **b, int print);

void				pa(t_list **a, t_list **b, int print);
void				pb(t_list **a, t_list **b, int print);
void				ra(t_list **a, int print);
void				rb(t_list **b, int print);
void				rr(t_list **a, t_list **b, int print);

void				rra(t_list **a, int print);
void				rrb(t_list **b, int print);
void				rrr(t_list **a, t_list **b, int print);
void				simple_sort(t_list **a, t_list **b);
void				chunk_sort(t_list **a, t_list **b);
void				radix_sort(t_list **a, t_list **b);

int					is_valid(const char *src);

t_list				*pars_args(int ac, char **av);

/* util functions */
int					is_in_stack(t_list *stack, int num);
int					is_valid_token_helper(const char *num);
int					valid_checker(int ac, char **av);
int					is_sorted(t_list *stack);
int					*assign_indexes(t_list *stack, int size);
int					command_checker(char **av, t_flags *f);


void				delete_matrix(char **matrix);
void				delete_stack(t_list *stack);

void				sort_two(t_list **a);
void				sort_three(t_list **a);
void				sort_five(t_list **a, t_list **b);
void				push_min_to_b(t_list **a, t_list **b);

int					ft_putnbr_u(unsigned int n);
void				print_disorder(double disorder);
void				print_strategy(t_strategy strategy, double disorder);
void				print_total_operations(t_bench *bench);
void				print_operations(t_bench *t_bench);

double				compute_disorder(t_list *stack);
void				choose_sort(t_list **a, t_list **b, t_strategy cmd,
						double disorder);

t_bench				*original_bench(void);

#endif
