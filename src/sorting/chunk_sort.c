/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:57:54 by mgogjyan          #+#    #+#             */
/*   Updated: 2026/04/23 19:00:46 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_chunk_max(int *vals, int i, int step, int size)
{
	if (i + step - 1 < size)
		return (vals[i + step - 1] + 1);
	return (vals[size - 1] + 1);
}

void	push_chunk(t_list **a, t_list **b, int min, int max)
{
	int	len;

	len = ft_lstsize(*a);
	while (len-- > 0)
	{
		if (*(int *)(*a)->content >= min && *(int *)(*a)->content < max)
			pb(a, b, 1);
		else
			ra(a, 1);
	}
}

static void	push_all_chunks(t_list **a, t_list **b, int *vals, int step)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(*a);
	while (i < size)
	{
		push_chunk(a, b, vals[i], get_chunk_max(vals, i, step, size));
		i += step;
	}
}

void	chunk_sort(t_list **a, t_list **b)
{
	int	size;
	int	step;
	int	*vals;

	size = ft_lstsize(*a);
	step = 0;
	while (step * step < size)
		step++;
	vals = malloc(size * sizeof(int));
	if (!vals)
		return ;
	fill_vals(vals, *a);
	sort_vals(vals, size);
	push_all_chunks(a, b, vals, step);
	free(vals);
	push_back_to_a(a, b);
}
