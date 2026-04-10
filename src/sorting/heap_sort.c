
#include "push_swap.h"

static int *get_content (t_list *stack, int index)
{
    while (index--)
        stack = stack->next;
    return ((int *)stack->content);
}

static void swap_content(int *first, int *second)
{
    int tmp;

    tmp = *first;
    *first = *second;
    *second = tmp;
}
static void heapify(t_list **stack, int size, int index)
{
    int max_idx;
    int left_idx;
    int right_idx;

    max_idx = index;
    left_idx = 2 * index + 1;
    right_idx = 2 * index + 2;

    if (left_idx < size && *get_content(*stack, left_idx) > *get_content(*stack, max_idx))
        max_idx = left_idx;
    if (right_idx < size && *get_content(*stack, right_idx) > *get_content(*stack, max_idx))
        max_idx = right_idx;
    if (max_idx != index)
    {
        swap_content(get_content(*stack, index), get_content(*stack, max_idx));
        heapify(stack, size, max_idx);
    }
}

void    heap_sort(t_list **a, t_list **b)
{
    int index;
    int size;

    while (*a)
        pb (a, b);
    size = ft_lstsize(b);
    index = size / 2 - 1;
    while (index >= 0)
    {
        heapify(b, size, index);
        index--;
    }
    index = size - 1;
    while (index > 0)
    {
        pa(a, b);
        rrb(b);
        heapify(b, index, 0);
        index--;
    }
}