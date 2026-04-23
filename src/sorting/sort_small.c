/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 19:02:21 by mgogjyan          #+#    #+#             */
/*   Updated: 2026/04/18 20:08:10 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **a)
{
	if (*(int *)(*a)->content > *(int *)(*a)->next->content)
		sa(a, 1);
}

void	sort_three(t_list **a)
{
	int	*arr;

	arr = assign_indexes(*a, 3);
	if (!arr)
		return ;
	if (arr[0] == 0 && arr[1] == 1)
		return (free(arr));
	else if (arr[0] == 0 && arr[1] == 2)
	{
		rra(a, 1);
		sa(a, 1);
	}
	else if (arr[0] == 1 && arr[1] == 0)
		sa(a, 1);
	else if (arr[0] == 1 && arr[1] == 2)
		rra(a, 1);
	else if (arr[0] == 2 && arr[1] == 0)
		ra(a, 1);
	else if (arr[0] == 2 && arr[1] == 1)
	{
		sa(a, 1);
		rra(a, 1);
	}
	free(arr);
}

static int	find_rank_pos(int *arr, int size, int rank)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i] == rank)
			return (i);
		i++;
	}
	return (-1);
}

void	push_min_to_b(t_list **a, t_list **b)
{
	int	*arr;
	int	size;
	int	pos;
	int	steps;

	size = ft_lstsize(*a);
	arr = assign_indexes(*a, size);
	if (!arr)
		return ;
	pos = find_rank_pos(arr, size, 0);
	free(arr);
	if (pos <= size / 2)
	{
		steps = pos;
		while (steps-- > 0)
			ra(a, 1);
	}
	else
	{
		steps = size - pos;
		while (steps-- > 0)
			rra(a, 1);
	}
	pb(a, b, 1);
}

void	sort_five(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) != 5)
		return ;
	push_min_to_b(a, b);
	push_min_to_b(a, b);
	sort_three(a);
	if (*(int *)(*b)->content > *(int *)(*b)->next->content)
		sb(b, 1);
	pa(a, b, 1);
	pa(a, b, 1);
}
