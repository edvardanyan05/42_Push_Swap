/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmvarda <edmvarda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 17:22:16 by edmvarda          #+#    #+#             */
/*   Updated: 2026/04/23 17:23:42 by edmvarda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_bench	*original_bench(void)
{
	static t_bench	dummy;

	return (&dummy);
}
