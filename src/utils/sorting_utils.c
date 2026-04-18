/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 20:15:34 by edmvarda          #+#    #+#             */
/*   Updated: 2026/04/18 20:07:28 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static int	get_rank(t_list *stack, t_list *node)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (*(int *)node->content > *(int *)stack->content)
			count++;
		stack = stack->next;
	}
	return (count);
}

int	*assign_indexes(t_list *stack, int size)
{
	t_list	*it;
	int		*arr;
	int		pos;

	arr = malloc(size * sizeof(int));
	if (!arr)
		return (NULL);
	it = stack;
	pos = 0;
	while (it)
	{
		arr[pos++] = get_rank(stack, it);
		it = it->next;
	}
	return (arr);
}

double	compute_disorder(t_list *stack)
{
	t_list	*it;
	int		mistakes;
	int		total_pairs;

	mistakes = 0;
	total_pairs = 0;
	while (stack)
	{
		it = stack->next;
		while (it)
		{
			total_pairs++;
			if (*(int *)stack->content > *(int *)it->content)
				mistakes++;
			it = it->next;
		}
		stack = stack->next;
	}
	return ((double)mistakes / total_pairs);
}
