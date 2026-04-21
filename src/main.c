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

static t_list* do_parse(int argc, char **argv, int arg_i);
static void do_sort(t_strategy commands, int bench_flag);
static void	print_bench(double disorder, t_strategy commands);

int	main(int argc, char **argv)
{
	int			arg_i;
	int			command_flag;
	int			bench_flag;
	t_strategy	commands;

	if (argc < 2)
		return (0);
	arg_i = 1;
	commands = ADAPTIVE;
	bench_flag = 0;
	command_flag = 0;
	while (argc > arg_i && argv[arg_i][0] == '-' && argv[arg_i][1] == '-'
		&& arg_i <= 3)
	{
		if (ft_strncmp(argv[arg_i], "--adaptive", 10) == 0
			&& argv[arg_i][10] == '\0' && !command_flag)
		{
			commands = ADAPTIVE;
			command_flag = 1;
		}
		else if (ft_strncmp(argv[arg_i], "--simple", 8) == 0
			&& argv[arg_i][8] == '\0' && !command_flag)
		{
			commands = SIMPLE;
			command_flag = 1;
		}
		else if (ft_strncmp(argv[arg_i], "--medium", 8) == 0
			&& argv[arg_i][8] == '\0' && !command_flag)
		{
			commands = MEDIUM;
			command_flag = 1;
		}
		else if (ft_strncmp(argv[arg_i], "--complex", 9) == 0
			&& argv[arg_i][9] == '\0' && !command_flag)
		{
			commands = COMPLEX;
			command_flag = 1;
		}
		else if (ft_strncmp(argv[arg_i], "--bench", 7) == 0
			&& argv[arg_i][7] == '\0' && !bench_flag)
			bench_flag = 1;
		else
		{
			write(2, "Error\n", 6);
			return (0);
		}
		arg_i++;
	}
	if (!do_parse(argc, argv, arg_i))
		return (0);
	do_sort(commands , bench_flag);
	return (0);
}

static t_list* do_parse(int argc, char **argv, int arg_i)
{
	static t_list	*a;

	if(!argc)
		return(a);
	a = pars_args(argc - arg_i + 1, argv + arg_i - 1);
	if (!a)
		return (0);
	if (is_sorted(a))
		return (delete_stack(a), 0);
	return (a);
}

static void do_sort(t_strategy commands, int bench_flag)
{
	t_list *a;
	t_list *b;
	double disorder;

	a = do_parse(0,0,0);
	b = NULL;
	disorder = compute_disorder(a);
	if (commands == SIMPLE)
		simple_sort(&a, &b);
	else if (commands == MEDIUM)
		chunk_sort(&a, &b);
	else if (commands == COMPLEX)
		radix_sort(&a, &b);
	else
	{
		if (disorder < 0.2)
			simple_sort(&a, &b);
		else if (disorder < 0.5)
			chunk_sort(&a, &b);
		else
			radix_sort(&a, &b);
	}
	if (bench_flag)
		print_bench(disorder, commands);
	delete_stack(a);
	delete_stack(b);
}

static void	print_bench(double disorder, t_strategy commands)
{
	print_disorder(disorder);
	print_strategy(commands, disorder);
	print_total_operations(original_bench());
    print_operations(original_bench());
}
