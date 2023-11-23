/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:20:38 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/23 13:38:18 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_strnstr(const char *haystack, const char *needle, size_t len, int ks)
{
	size_t	i;
	size_t	j;
	int		kd;

	i = 0;
	kd = 0;
	if (needle[i] == '\0')
		return (1);
	while (haystack[i] && i < len)
	{
		j = 0;
		if (haystack[i] == '\"')
			kd++;
		if (haystack[i] == '\'')
			ks++;
		while (haystack[i + j] == needle[j] && \
			i + j < len && (kd % 2) == 0 && (ks % 2) == 0)
		{
			if (needle[j + 1] == '\0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
