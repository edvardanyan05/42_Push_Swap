/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 18:00:37 by mgogjyan          #+#    #+#             */
/*   Updated: 2026/04/18 20:08:38 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*it;
	t_list	*tmp;

	tmp = *stack;
	*stack = (*stack)->next;
	it = *stack;
	while (it->next)
		it = it->next;
	it->next = tmp;
	tmp->next = NULL;
}

void	ra(t_list **a, int print)
{
	if (!a || !*a || !(*a)->next)
		return ;
	rotate(a);
	if (print)
	{
		write(1, "ra\n", 3);
		original_bench()->ra++;
	}
}

void	rb(t_list **b, int print)
{
	if (!b || !*b || !(*b)->next)
		return ;
	rotate(b);
	if (print)
	{
		write(1, "rb\n", 3);
		original_bench()->rb++;
	}
}

void	rr(t_list **a, t_list **b, int print)
{
	if (a && *a && (*a)->next && b && *b && (*b)->next)
	{
		rotate(a);
		rotate(b);
		if (print)
		{
			write(1, "rr\n", 3);
			original_bench()->rr++;
		}
	}
}
