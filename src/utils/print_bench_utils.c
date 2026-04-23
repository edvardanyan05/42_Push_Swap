/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:21:20 by mgogjyan          #+#    #+#             */
/*   Updated: 2026/04/23 22:24:18 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putnbr_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_u(n / 10);
	count += write(2, &"0123456789"[n % 10], 1);
	return (count);
}

void	print_disorder(double disorder)
{
	unsigned int	left;
	unsigned int	right;

	disorder = disorder * 100;
	left = (unsigned int)disorder;
	right = (unsigned int)((disorder - left) * 100);
	write(2, "Disorder: ", 10);
	ft_putnbr_u(left);
	write(2, ".", 1);
	if (right < 10)
		write(2, "0", 1);
	ft_putnbr_u(right);
	write(2, "%\n", 2);
}

void	print_strategy(t_strategy strategy, double disorder)
{
	if (strategy == SIMPLE)
		write(2, "Strategy: Simple Sort O(n^2)\n", 29);
	else if (strategy == MEDIUM)
		write(2, "Strategy: Chunk Sort O(n sqrt(n))\n", 34);
	else if (strategy == COMPLEX)
		write(2, "Strategy: Radix Sort O(n log n)\n", 32);
	else
	{
		if (disorder < 0.2)
			write(2, "Strategy: Simple Sort O(n^2)\n", 29);
		else if (disorder < 0.5)
			write(2, "Strategy: Chunk Sort O(n sqrt(n))\n", 34);
		else
			write(2, "Strategy: Radix Sort O(n log n)\n", 32);
	}
}

void	print_total_operations(t_bench *bench)
{
	unsigned int	total;

	total = bench->sa + bench->sb + bench->ss + bench->pa + bench->pb
		+ bench->ra + bench->rb + bench->rr + bench->rra + bench->rrb
		+ bench->rrr;
	write(2, "Total operations: ", 18);
	ft_putnbr_u(total);
	write(2, "\n", 1);
}

void	print_operations(t_bench *bench)
{
	write(2, "sa: ", 4);
	ft_putnbr_u(bench->sa);
	write(2, "\nsb: ", 5);
	ft_putnbr_u(bench->sb);
	write(2, "\nss: ", 5);
	ft_putnbr_u(bench->ss);
	write(2, "\npa: ", 5);
	ft_putnbr_u(bench->pa);
	write(2, "\npb: ", 5);
	ft_putnbr_u(bench->pb);
	write(2, "\nra: ", 5);
	ft_putnbr_u(bench->ra);
	write(2, "\nrb: ", 5);
	ft_putnbr_u(bench->rb);
	write(2, "\nrr: ", 5);
	ft_putnbr_u(bench->rr);
	write(2, "\nrra: ", 6);
	ft_putnbr_u(bench->rra);
	write(2, "\nrrb: ", 6);
	ft_putnbr_u(bench->rrb);
	write(2, "\nrrr: ", 6);
	ft_putnbr_u(bench->rrr);
	write(2, "\n", 1);
}
