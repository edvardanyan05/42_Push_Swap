/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_func_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmvarda <edmvarda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 16:21:59 by mgogjyan          #+#    #+#             */
/*   Updated: 2026/04/23 16:21:43 by edmvarda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bench	*original_bench(void)
{
	static t_bench	bench;

	return (&bench);
}

void	choose_sort(t_list **a, t_list **b, t_strategy cmd, double disorder)
{
	if (cmd == SIMPLE)
		simple_sort(a, b);
	else if (cmd == MEDIUM)
		chunk_sort(a, b);
	else if (cmd == COMPLEX)
		radix_sort(a, b);
	else if (disorder < 0.2)
		simple_sort(a, b);
	else if (disorder < 0.5)
		chunk_sort(a, b);
	else
		radix_sort(a, b);
}

int	command_checker(char **av, t_flags *f)
{
	int	i;
	int	cmd_flag;
	int	bench_flag;

	i = 1;
	cmd_flag = 0;
	bench_flag = 0;
	while (i < f->arg_i)
	{
		if (ft_strncmp(av[i], "--bench", 7) == 0)
			bench_flag++;
		else
			cmd_flag++;
		i++;
	}
	if (bench_flag > 1 || cmd_flag > 1)
		return (0);
	return (1);
}
