/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmvarda <edmvarda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 20:47:53 by edmvarda          #+#    #+#             */
/*   Updated: 2026/03/22 20:47:54 by edmvarda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    int arg_i;
    int bench;
    t_list *stack;
    t_list *reserve;

    t_strategy  commands;

    if (argc < 2)
        return (0);
    arg_i = 1;
    commands = ADAPTIVE;
    if(argc > arg_i && argv[arg_i][0] == '-' && argv[arg_i][1] == '-')
    {
        if(ft_strncmp(argv[1], "--adaptive", 10) == 0)
            commands = ADAPTIVE;
        else if(ft_strncmp(argv[1], "--simple", 8) == 0)
            commands = SIMPLE;
        else if(ft_strncmp(argv[1], "--medium", 8) == 0)
            commands = MEDIUM;
        else if(ft_strncmp(argv[1], "--complex", 9) == 0)
            commands = COMPLEX;
        else
        {
            write(2, "Error\n", 6);
            return (0);
        }
        arg_i++;
    }
    bench = 0;
    if (argc > arg_i && ft_strncmp(argv[arg_i], "--bench", 7) == 0)
    {
        bench = 1;
        arg_i++;
    }
    stack = pars_args(argc - arg_i + 1, argv + arg_i - 1);
    if (!stack)
        return (0);
    if (is_sorted(stack))
        return (delete_stack(stack), 0);
    reserve = NULL;
    if (commands == SIMPLE)
        simple_sort(&stack, &reserve);
    else if (commands == MEDIUM)
        chunk_sort(&stack, &reserve);
    else if (commands == COMPLEX)
        radix_sort(&stack, &reserve);
    else
    {
        
    }
}
