/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:29:28 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/26 13:13:32 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_doublesize(const char *s, char c)
{
	int	size;

	size = 0;
	while (*s)
	{
		if ((s[1] == c || !s[1]) && *s != c)
			size++;
		s++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	i;
	int		j;
	int		start;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (ft_doublesize(s, c) + 1));
	if (!result)
		return (NULL);
	start = -1;
	i = -1;
	j = 0;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if (start >= 0 && (s[i] == c || i == ft_strlen(s)))
		{
			result[j++] = ft_substr(s, start, (i - start));
			start = -1;
		}
	}
	result[j] = NULL;
	return (result);
}
