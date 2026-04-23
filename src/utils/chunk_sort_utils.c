/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 18:58:19 by mgogjyan          #+#    #+#             */
/*   Updated: 2026/04/23 18:58:28 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_pos(t_list **b)
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

void	rotate_to_top(t_list **b, int pos)
{
	int	size;

	size = ft_lstsize(*b);
	if (pos <= size / 2)
		while (pos-- > 0)
			rb(b, 1);
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrb(b, 1);
	}
}

void	push_back_to_a(t_list **a, t_list **b)
{
	while (*b)
	{
		rotate_to_top(b, find_max_pos(b));
		pa(a, b, 1);
	}
}

void	fill_vals(int *vals, t_list *a)
{
	int	i;

	i = 0;
	while (a)
	{
		vals[i] = *(int *)a->content;
		a = a->next;
		i++;
	}
}

void	sort_vals(int *arr, int size)
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
