
#include "push_swap.h"

int is_sorted(t_list *stack)
{
    while (stack && stack->next)
    {
        if (*(int *)stack->content > *(int *)stack->next->content)
            return (0);
        stack = stack->next;
    }
    return (1);
}