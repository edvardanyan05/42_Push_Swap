/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 22:31:54 by mgogjyan          #+#    #+#             */
/*   Updated: 2026/04/21 23:21:59 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_bits_size(int size)
{
	int	bits;

	bits = 0;
	while ((1 << bits) < size)
		bits++;
	return (bits);
}

static void	radix_sort_helper(t_list **a, t_list **b, int *arr, int bit)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(*a);
	while (i < size)
	{
		if (((arr[i] >> bit) & 1) == 1)
			ra(a);
		else
			pb(a, b);
		i++;
	}
}

void	radix_sort(t_list **a, t_list **b)
{
	int	size;
	int	bits_size;
	int	bit;
	int	*arr;

	size = ft_lstsize(*a);
	bits_size = get_bits_size(size);
	bit = 0;
	while (bit < bits_size)
	{
		arr = assign_indexes(*a, size);
		if (!arr)
			return ;
		radix_sort_helper(a, b, arr, bit);
		free(arr);
		while (*b)
			pa(a, b);
		bit++;
	}
}
