/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 19:38:45 by mgogjyan          #+#    #+#             */
/*   Updated: 2026/04/11 22:06:07 by mgogjyan         ###   ########.fr       */
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

static int	find_max_pos(t_list **b)
{
	int		max_pos;
	int		pos;
	int		max_value;
	t_list	*it;

	pos = 0;
	max_pos = 0;
	if (!b || !*b || !(*b)->content)
		return (0);
	it = *b;
	max_value = *(int *)it->content;
	while (it)
	{
		if (*(int *)it->content > max_value)
		{
			max_value = *(int *)it->content;
			max_pos = pos;
		}
		pos++;
		it = it->next;
	}
	return (max_pos);
}

static void	rotate_to_top(t_list **b, int pos)
{
	int	size;

	size = ft_lstsize(*b);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rb(b);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(b);
	}
}

void	push_chunk(t_list **a, t_list **b, int chunk_min, int chunk_max)
{
	int	size_a;
	int	*arr;
	int	i;

	size_a = ft_lstsize(*a);
	i = 0;
	while (i < size_a)
	{
		arr = assign_indexes(*a, ft_lstsize(*a));
		if (!arr)
			return ;
		if (arr[0] >= chunk_min && arr[0] < chunk_max)
			pb(a, b);
		else
			ra(a);
		free(arr);
		i++;
	}
}
