/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edmvarda <edmvarda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:39:52 by edmvarda          #+#    #+#             */
/*   Updated: 2026/02/17 20:27:00 by edmvarda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_of_strings(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
		{
			while (s[i] && s[i] == c)
				i++;
		}
	}
	return (count);
}

static size_t	count_of_letters(char const *s, char c, size_t dest,
		size_t *start)
{
	size_t	index;
	size_t	i;
	size_t	len;

	index = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		if (++index == dest)
		{
			*start = i;
			len = 0;
			while (s[i] && s[i] != c && ++len)
				i++;
			return (len);
		}
		while (s[i] && s[i] != c)
			i++;
	}
	return (0);
}

static void	free_arr(char **arr, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(arr[i]);
		arr[i] = 0;
		i++;
	}
	free(arr);
	arr = 0;
}

static char	**create_dynamic_matrix(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	count;
	size_t	len;
	size_t	start;

	count = count_of_strings(s, c);
	arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!arr)
		return (0);
	i = 0;
	while (i < count)
	{
		len = count_of_letters(s, c, i + 1, &start);
		arr[i] = ft_substr(s, start, len);
		if (!arr[i])
		{
			free_arr(arr, i);
			return (0);
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	if (!s)
		return (0);
	return (create_dynamic_matrix(s, c));
}
