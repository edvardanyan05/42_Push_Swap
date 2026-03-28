/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    parse_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmvarda <edmvarda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 19:02:21 by mgogjyan          #+#    #+#             */
/*   Updated: 2026/03/28 20:16:40 by edmvarda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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
		if (!matrix)
			return (NULL);
		matrix_i = 0;
		while (matrix[matrix_i])
		{
			new_node = (t_list *)malloc(sizeof(t_list));
			if (!new_node)
				return (NULL);
			new_node->content = malloc(sizeof(int));
			if (!new_node || !new_node->content)
				return (NULL);
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
