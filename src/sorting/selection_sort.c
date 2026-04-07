/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:15:48 by mgogjyan          #+#    #+#             */
/*   Updated: 2026/04/07 14:36:20 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	simple_sort(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 3)
		push_min_to_b(a, b);
	if (ft_lstsize(*a) == 3)
		sort_three(a);
	while (*b)
		pa(a, b);
}
