/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 20:47:53 by edmvarda          #+#    #+#             */
/*   Updated: 2026/04/21 23:35:56 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_sort(t_list *a, t_strategy cmd, int bench_flag);
static void	print_bench(double disorder, t_strategy commands);
static int	parse_flags(int argc, char **argv, t_flags *f);

int	main(int argc, char **argv)
{
	t_flags	f;
	t_list	*a;

	if (argc < 2)
		return (0);
	f.arg_i = 1;
	f.bench = 0;
	f.cmd = ADAPTIVE;
	if (!parse_flags(argc, argv, &f) || !command_checker(argv, &f))
		return (write(2, "Error\n", 6), 0);
	a = pars_args(argc - f.arg_i + 1, argv + f.arg_i - 1);
	if (!a)
		return (0);
	if (is_sorted(a))
		return (delete_stack(a), 0);
	do_sort(a, f.cmd, f.bench);
	return (0);
}

static int	parse_flags(int argc, char **argv, t_flags *f)
{
	while (argc > f->arg_i && argv[f->arg_i][0] == '-'
		&& argv[f->arg_i][1] == '-')
	{
		if (ft_strncmp(argv[f->arg_i], "--adaptive", 10) == 0
			&& argv[f->arg_i][10] == '\0')
			f->cmd = ADAPTIVE;
		else if (ft_strncmp(argv[f->arg_i], "--simple", 8) == 0
			&& argv[f->arg_i][8] == '\0')
			f->cmd = SIMPLE;
		else if (ft_strncmp(argv[f->arg_i], "--medium", 8) == 0
			&& argv[f->arg_i][8] == '\0')
			f->cmd = MEDIUM;
		else if (ft_strncmp(argv[f->arg_i], "--complex", 9) == 0
			&& argv[f->arg_i][9] == '\0')
			f->cmd = COMPLEX;
		else if (ft_strncmp(argv[f->arg_i], "--bench", 7) == 0
			&& argv[f->arg_i][7] == '\0')
			f->bench = 1;
		else
			return (0);
		f->arg_i++;
	}
	return (1);
}

static void	do_sort(t_list *a, t_strategy cmd, int bench_flag)
{
	t_list	*b;
	double	disorder;

	b = NULL;
	disorder = compute_disorder(a);
	choose_sort(&a, &b, cmd, disorder);
	if (bench_flag)
		print_bench(disorder, cmd);
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
