/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 20:05:45 by edmvarda          #+#    #+#             */
/*   Updated: 2026/04/18 20:07:24 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_token_helper(const char *num)
{
	int	i;

	i = 0;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	valid_checker(int ac, char **av)
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
