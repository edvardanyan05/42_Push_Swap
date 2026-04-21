/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_func_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:21:59 by mgogjyan          #+#    #+#             */
/*   Updated: 2026/04/21 19:37:21 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bench	*original_bench(void)
{
	static t_bench	bench;

	return (&bench);
}

void	choose_sort(t_list **a, t_list **b, t_strategy cmd, double disorder)
{
	if (cmd == SIMPLE)
		simple_sort(a, b);
	else if (cmd == MEDIUM)
		chunk_sort(a, b);
	else if (cmd == COMPLEX)
		radix_sort(a, b);
	else if (disorder < 0.2)
		simple_sort(a, b);
	else if (disorder < 0.5)
		chunk_sort(a, b);
	else
		radix_sort(a, b);
}
