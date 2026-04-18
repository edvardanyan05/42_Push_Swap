/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:15:48 by mgogjyan          #+#    #+#             */
/*   Updated: 2026/04/18 20:08:14 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_list **a, t_list **b)
{
	if (!a || ft_lstsize(*a) == 0 || ft_lstsize(*a) == 1)
		return ;
	if (ft_lstsize(*a) == 2)
	{
		sort_two(a);
		return ;
	}
	while (ft_lstsize(*a) > 3)
		push_min_to_b(a, b);
	sort_three(a);
	while (*b)
		pa(a, b);
}
