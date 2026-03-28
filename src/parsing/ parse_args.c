/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    parse_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 19:02:21 by mgogjyan          #+#    #+#             */
/*   Updated: 2026/03/28 18:48:22 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	valid_checker(int ac, char **av)
{
	int	arg_i;

	arg_i = 1;
	while (arg_i < ac)
	{
		if (!is_valid(av[arg_i]))
			return (0);
		arg_i++;
	}
	return (1);
}

t_list	*fill_stack(int ac, char **av)
{
	t_list	*stack;
	t_list	*new_node;
	char	**matrix;
	int		arg_i;
	int		matrix_i;

	arg_i = 1;
	stack = NULL;
	while (arg_i < ac)
	{
		matrix = ft_split(av[arg_i], ' ');
		matrix_i = 0;
		while (matrix[matrix_i])
		{
			new_node = (t_list *)malloc(sizeof(t_list));
			new_node->content = malloc(sizeof(int));
			*(int *)new_node->content = ft_atoi(matrix[matrix_i]);
			ft_lstadd_back(&stack, new_node);
			matrix_i++;
		}
		arg_i++;
	}
	return (stack);
}

t_list	*pars_args(int ac, char **av)
{
	t_list	*a;

	if (!valid_checker(ac, av))
		return (NULL);
	a = fill_stack(ac, av);
	return (a);
}
