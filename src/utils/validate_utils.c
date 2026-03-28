/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmvarda <edmvarda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 20:05:45 by edmvarda          #+#    #+#             */
/*   Updated: 2026/03/28 20:21:59 by edmvarda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_token_helper(const char *num)
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

static int	is_valid_token(const char *token)
{
	char	*limit;
	char	*num;
	int		len;

	if (!token || token[0] == '\0')
		return (0);
	if (token[0] == '+' || token[0] == '-')
		num = token + 1;
	else
		num = token;
	if (!is_valid_token_helper(num))
		return (0);
	len = ft_strlen(num);
	if (len < 10)
		return (1);
	if (len > 10)
		return (0);
	if (token[0] == '-')
		limit = "2147483648";
	else
		limit = "2147483647";
	if (ft_strncmp(num, limit, 10) > 0)
		return (0);
	return (1);
}

int	token_creator(const char *src)
{
	char	token[12];
	int		src_i;
	int		token_i;
	int		has_digit;

	src_i = 0;
	has_digit = 0;
	while (src[src_i])
	{
		token_i = 0;
		while (src[src_i] == ' ')
			src_i++;
		while (src[src_i] != ' ' && src[src_i] != '\0')
		{
			if (token_i >= 11)
				return (0);
			has_digit = 1;
			token[token_i++] = src[src_i++];
		}
		token[token_i] = '\0';
		if (!is_valid_token(token))
			return (0);
	}
	return (has_digit);
}

int	no_duplicate(int ac, char **av)
{
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
