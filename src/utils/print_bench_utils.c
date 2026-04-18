
#include "push_swap.h"

int	ft_putnbr_u(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_u(n / 10);
	count += write(2, "0123456789" + (n % 10), 1);
	return (count);
}

void print_disorder(double disorder)
{
    unsigned int left;
    unsigned int right;

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

void print_strategy (t_strategy strategy, double disorder)
{
    if (strategy == SIMPLE)
        write(2, "Strategy: Simple Sort O(n^2)\n", 29);
    else if (strategy == MEDIUM)
        write(2, "Strategy: Chunk Sort O(n sqrt(n))\n", 34);
    else if (strategy == COMPLEX)
        write(2, "Strategy: Radix Sort O(n log n)\n", 32);
    else
    {
        if (disorder < 0.1)
            write(2, "Strategy: Simple Sort O(n^2)\n", 29);
        else if (disorder < 0.5)
            write(2, "Strategy: Chunk Sort O(n sqrt(n))\n", 34);
        else
            write(2, "Strategy: Radix Sort O(n log n)\n", 32);
    }
}

void print_total_operations(t_bench *bench)
{
    unsigned int total;

    total = bench->sa + bench->sb + bench->ss + bench->pa + bench->pb
        + bench->ra + bench->rb + bench->rr + bench->rra + bench->rrb + bench->rrr;
    write(2, "Total operations: ", 18);
    ft_putnbr_u(total);
    write(2, "\n", 1);
}
