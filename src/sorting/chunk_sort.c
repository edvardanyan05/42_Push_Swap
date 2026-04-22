/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 19:38:45 by mgogjyan          #+#    #+#             */
/*   Updated: 2026/04/23 16:00:00 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_pos(t_list **b)
{
	int		pos;
	int		max_pos;
	int		max;
	t_list	*tmp;

	if (!b || !*b)
		return (0);
	pos = 0;
	max_pos = 0;
	max = *(int *)(*b)->content;
	tmp = *b;
	while (tmp)
	{
		if (*(int *)tmp->content > max)
		{
			max = *(int *)tmp->content;
			max_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	return (max_pos);
}

static void	rotate_to_top(t_list **b, int pos)
{
	int	size;

	size = ft_lstsize(*b);
	if (pos <= size / 2)
		while (pos-- > 0)
			rb(b);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(b);
	}
}

static void	sort_vals(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	push_chunk(t_list **a, t_list **b, int min, int max)
{
	int	len;

	len = ft_lstsize(*a);
	while (len-- > 0)
	{
		if (*(int *)(*a)->content >= min && *(int *)(*a)->content < max)
			pb(a, b);
		else
			ra(a);
	}
}

void	chunk_sort(t_list **a, t_list **b)
{
	int		size;
	int		step;
	int		i;
	int		*vals;
	t_list	*tmp;

	size = ft_lstsize(*a);
	step = 0;
	while (step * step < size)
		step++;
	vals = malloc(size * sizeof(int));
	if (!vals)
		return ;
	tmp = *a;
	i = 0;
	while (tmp)
		vals[i++] = *(int *)tmp->content, tmp = tmp->next;
	sort_vals(vals, size);
	i = 0;
	while (i < size)
	{
		push_chunk(a, b, vals[i], vals[(i + step < size) ? i + step - 1 : size - 1] + 1);
		i += step;
	}
	free(vals);
	while (*b)
	{
		rotate_to_top(b, find_max_pos(b));
		pa(a, b);
	}
}