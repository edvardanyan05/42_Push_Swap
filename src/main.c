/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 20:47:53 by edmvarda          #+#    #+#             */
/*   Updated: 2026/04/18 20:36:34 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_bench(double disorder, t_strategy commands, t_bench *bench);

int	main(int argc, char **argv)
{
	int			arg_i;
	int			bench;
	double		disorder;
	t_list		*a;
	t_list		*b;
	t_strategy	commands;

	if (argc < 2)
		return (0);
	arg_i = 1;
	commands = ADAPTIVE;
	bench = 0;
	while (argc > arg_i && argv[arg_i][0] == '-' && argv[arg_i][1] == '-'
		&& arg_i <= 3)
	{
		if (ft_strncmp(argv[arg_i], "--adaptive", 10) == 0
			&& argv[arg_i][10] == '\0')
			commands = ADAPTIVE;
		else if (ft_strncmp(argv[arg_i], "--simple", 8) == 0
			&& argv[arg_i][8] == '\0')
			commands = SIMPLE;
		else if (ft_strncmp(argv[arg_i], "--medium", 8) == 0
			&& argv[arg_i][8] == '\0')
			commands = MEDIUM;
		else if (ft_strncmp(argv[arg_i], "--complex", 9) == 0
			&& argv[arg_i][9] == '\0')
			commands = COMPLEX;
		else if (ft_strncmp(argv[arg_i], "--bench", 7) == 0
			&& argv[arg_i][7] == '\0')
			bench = 1;
		else
		{
			write(2, "Error\n", 6);
			return (0);
		}
		arg_i++;
	}
	if (argc > arg_i && ft_strncmp(argv[arg_i], "--bench", 7) == 0
		&& argv[arg_i][7] == '\0' && bench != 1)
	{
		bench = 1;
		arg_i++;
	}
	a = pars_args(argc - arg_i + 1, argv + arg_i - 1);
	if (!a)
		return (0);
	if (is_sorted(a))
		return (delete_stack(a), 0);
	b = NULL;
	if (commands == SIMPLE)
		simple_sort(&a, &b);
	else if (commands == MEDIUM)
		chunk_sort(&a, &b);
	else if (commands == COMPLEX)
		radix_sort(&a, &b);
	else
	{
		disorder = compute_disorder(a);
		if (disorder < 0.2)
			simple_sort(&a, &b);
		else if (disorder < 0.5)
			chunk_sort(&a, &b);
		else
			radix_sort(&a, &b);
	}
	delete_stack(a);
	delete_stack(b);
	return (0);
}

static void	print_bench(double disorder, t_strategy commands, t_bench *bench)
{
	print_disorder(disorder);
	print_strategy(commands, disorder);
	print_total_operations(original_bench());
    print_operations(original_bench());
}