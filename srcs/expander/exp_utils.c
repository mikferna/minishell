/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:15:03 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/23 19:24:39 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*delete_quotes(char *str, char c)
{
	int		i;
	int		j;
	char	*tmp;
	char	**split;

	i = 1;
	j = 0;
	tmp = NULL;
	if (ft_strlen(str) == 2)
		return ("");
	split = ft_split(str, c);
	if (split[0])
		tmp = ft_substr(split[0], 0, ft_strlen(split[0]));
	while(split[0] && split[i])
	{
		tmp = ft_strjoin(tmp, split[i]);
		i++;
	}
	return (tmp);
}

size_t	dollar_sign(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (i + 1);
		i++;
	}
	return (0);
}

char	**ft_split_comillas(char const *s, char c)
{
	char	**result;
	size_t	i;
	int		j;
	int		start;
	int		comillad;
	int		comillas;

	comillad = 0;
	comillas = 0;
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
		if (s[i] == '"' && comillad == 0 && comillas == 0)
			comillad = 1;
		else if (s[i] == '\'' && comillad == 0 && comillas == 0)
			comillas = 1;
		else if (s[i] == '"' && comillad == 1 && comillas == 0)
			comillad = 0;
		else if (s[i] == '\'' && comillad == 0 && comillas == 1)
			comillas = 0;
		if (s[i] != c && start < 0)
			start = i;
		else if (start >= 0 && (s[i] == c || i == ft_strlen(s))
			&& (comillad == 0 && comillas == 0))
		{
			result[j++] = ft_substr(s, start, (i - start));
			start = -1;
		}
	}
	result[j] = NULL;
	return (result);
}
