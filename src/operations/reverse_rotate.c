/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:36:10 by mgogjyan          #+#    #+#             */
/*   Updated: 2026/04/18 20:08:41 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rotate(t_list **stack)
{
	t_list	*it;
	t_list	*tmp;

	it = *stack;
	while (it->next->next)
		it = it->next;
	tmp = it->next;
	it->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
}

void	rra(t_list **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	rev_rotate(a);
	write(1, "rra\n", 4);
	original_bench()->rra++;
}

void	rrb(t_list **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	rev_rotate(b);
	write(1, "rrb\n", 4);
	original_bench()->rrb++;
}

void	rrr(t_list **a, t_list **b)
{
	if (a && *a && (*a)->next && b && *b && (*b)->next)
	{
		rev_rotate(a);
		rev_rotate(b);
		write(1, "rrr\n", 4);
		original_bench()->rrr++;
	}
}
