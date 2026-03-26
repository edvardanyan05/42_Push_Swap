/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgogjyan <mgogjyan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 20:31:24 by mgogjyan          #+#    #+#             */
/*   Updated: 2026/03/26 21:36:26 by mgogjyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid(char *src)
{
	int	i;

	i = 0;
	if (!src || src[0] == '\0')
		return (0);
	while (src[i])
	{
		if (ft_isdigit(src[i]) || src[i] == ' ')
			i++;
		else
		{
			if ((src[i] == '-' || src[i] == '+') && (ft_isdigit(src[i + 1])
					&& (i == 0 || src[i - 1] == ' ')))
				i++;
			else
				return (0);
		}
	}
	return (1);
}
