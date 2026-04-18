/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 19:11:43 by edmvarda          #+#    #+#             */
/*   Updated: 2026/03/26 18:31:18 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top(t_list **stack)
{
	t_list	*it;
	t_list	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	it = *stack;
	tmp = it->next;
	it->next = it->next->next;
	tmp->next = it;
	*stack = tmp;
}

void	sa(t_list **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	swap_top(a);
	write(1, "sa\n", 3);
	original_bench()->sa++;
}

void	sb(t_list **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	swap_top(b);
	write(1, "sb\n", 3);
	original_bench()->sb++;
}

void	ss(t_list **a, t_list **b)
{
	if ((!a || !*a || !(*a)->next) || (!b || !*b || !(*b)->next))
		return ;
	swap_top(a);
	swap_top(b);
	write(1, "ss\n", 3);
	original_bench()->ss++;
}
