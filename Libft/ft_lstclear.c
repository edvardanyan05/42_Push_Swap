/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmvarda <edmvarda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:17:23 by edmvarda          #+#    #+#             */
/*   Updated: 2026/02/17 17:17:42 by edmvarda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*it;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		it = *lst;
		*lst = (*lst)->next;
		del(it->content);
		free(it);
	}
}
