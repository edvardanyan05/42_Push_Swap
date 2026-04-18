/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 20:48:08 by edmvarda          #+#    #+#             */
/*   Updated: 2026/04/11 22:32:37 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

// operations benchmark struct
typedef struct s_bench
{
    int sa;
    int sb;
    int ss;
    int pa;
    int pb;
    int ra;
    int rb;
    int rr;
    int rra;
    int rrb;
    int rrr;
}   t_bench;

// flags for sorting strategy
typedef enum e_strategy
{
    ADAPTIVE,
    SIMPLE,
    MEDIUM,
    COMPLEX
}   t_strategy;


// main functions
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);

void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);

void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);

void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

void	simple_sort(t_list **a, t_list **b);
void	radix_sort(t_list **a, t_list **b);

int		is_valid(const char *src);

t_list	*pars_args(int ac, char **av);


// helper functions
int		is_in_stack(t_list *stack, int num);
int		is_valid_token_helper(const char *num);
int		valid_checker(int ac, char **av);
int		is_sorted(t_list *stack);
int		*assign_indexes(t_list *stack, int size);

void	delete_matrix(char **matrix);
void	delete_stack(t_list *stack);

void	sort_two(t_list **a);
void	sort_three(t_list **a);
void	sort_five(t_list **a, t_list **b);
void	push_min_to_b(t_list **a, t_list **b);

double	compute_disorder(t_list *stack);

t_bench    *original_bench(void);

#endif
