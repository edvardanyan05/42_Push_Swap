/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:51:25 by edmvarda          #+#    #+#             */
/*   Updated: 2026/03/26 18:08:03 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_top(t_list **dst, t_list **src)
{
	t_list	*tmp;

	if (!src || !(*src))
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pa(t_list **a, t_list **b)
{
	if (!a || !b || !*b)
		return ;
	push_top(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	if (!b || !a || !*a)
		return ;
	push_top(b, a);
	write(1, "pb\n", 3);
}
