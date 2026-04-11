/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 19:38:45 by mgogjyan          #+#    #+#             */
/*   Updated: 2026/04/11 19:38:53 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	chunk_size_counter(int stack_size)
{
	int	chunk_size;

	chunk_size = 0;
	while (chunk_size * chunk_size < stack_size)
		chunk_size++;
	return (chunk_size);
}

void	push_chunk(t_list **a, t_list **b, int chunk_min, int chunk_max)
{
	int size_a;

	size_a = chunk_size_counter(*a);
}