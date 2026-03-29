/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    parse_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 19:02:21 by mgogjyan          #+#    #+#             */
/*   Updated: 2026/03/30 01:18:10 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*fill_stack_no_duplicate(t_list *stack, char **matrix)
{
	t_list	*new_node;
	int		num;
	int		matrix_i;

	matrix_i = 0;
	while (matrix[matrix_i])
	{
		num = ft_atoi(matrix[matrix_i]);
		if (is_in_stack(stack, num))
			return (delete_stack(stack), NULL);
		new_node = (t_list *)malloc(sizeof(t_list));
		if (!new_node)
			return (delete_stack(stack), NULL);
		new_node->content = malloc(sizeof(int));
		if (!new_node->content)
			return (free(new_node), delete_stack(stack), NULL);
		*(int *)new_node->content = num;
		ft_lstadd_back(&stack, new_node);
		matrix_i++;
	}
	return (stack);
}

static t_list	*fill_stack(int ac, char **av)
{
	t_list	*stack;
	char	**matrix;
	int		arg_i;

	arg_i = 1;
	stack = NULL;
	while (arg_i < ac)
	{
		matrix = ft_split(av[arg_i], ' ');
		if (!matrix)
		{
			delete_stack(stack);
			return (NULL);
		}
		stack = fill_stack_no_duplicate(stack, matrix);
		delete_matrix(matrix);
		if (!stack)
			return (NULL);
		arg_i++;
	}
	return (stack);
}

t_list	*pars_args(int ac, char **av)
{
	t_list	*a;

	if (!valid_checker(ac, av))
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	a = fill_stack(ac, av);
	if (!a)
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	return (a);
}
