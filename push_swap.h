/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 20:48:08 by edmvarda          #+#    #+#             */
/*   Updated: 2026/03/28 15:47:11 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				sa(t_list **a);
void				sb(t_list **b);
void				ss(t_list **a, t_list **b);

void				pa(t_list **a, t_list **b);
void				pb(t_list **a, t_list **b);

void				ra(t_list **a);
void				rb(t_list **b);
void				rr(t_list **a, t_list **b);

void				rra(t_list **a);
void				rrb(t_list **b);
void				rrr(t_list **a, t_list **b);

int					is_valid(const char *src);

#endif
