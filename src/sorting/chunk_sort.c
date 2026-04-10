
#include "push_swap.h"

static int chunk_size_counter(int stack_size)
{
    int chunk_size;
    
    chunk_size = 0;
    while (chunk_size * chunk_size < stack_size)
        chunk_size++;
    return (chunk_size);
}

void    push_chunk(t_list **a, t_list **b, int chunk_min, int chunk_max, int size)
{
    
}