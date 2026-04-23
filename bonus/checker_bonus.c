#include "checker_bonus.h"

static void	error_exit(t_list *a, t_list *b)
{
	delete_stack(a);
	delete_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

static int	exec_cmd_two(char *line, t_list **a, t_list **b)
{
	if (!ft_strncmp(line, "ra\n", 3))
		ra(a, 0);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(b, 0);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(a, b, 0);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(a, 0);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(b, 0);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(a, b, 0);
	else
		return (0);
	return (1);
}

static void	execute_cmd(char *line, t_list **a, t_list **b)
{
	if (!ft_strncmp(line, "sa\n", 3))
		sa(a, 0);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(b, 0);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(a, b, 0);
	else if (!ft_strncmp(line, "pa\n", 3))
		pa(a, b, 0);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(a, b, 0);
	else if (!exec_cmd_two(line, a, b))
		error_exit(*a, *b);
}

static void	read_commands(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execute_cmd(line, a, b);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac < 2)
		return (0);
	a = pars_args(ac, av);
	if (!a)
		return (1);
	b = NULL;
	read_commands(&a, &b);
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	delete_stack(a);
	delete_stack(b);
	return (0);
}