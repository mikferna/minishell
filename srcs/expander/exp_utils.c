/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:15:03 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/27 13:00:06 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*delete_quotes(char *str, char c)
{
	int		i;
	char	*tmp;
	char	**split;
    char	*old_tmp;
	
	i = 1;
	tmp = NULL;
	if (ft_strlen(str) == 2)
		return ("");
	split = ft_split(str, c);
	if (!split)
		return (NULL);
	if (split[0])
		tmp = ft_substr(split[0], 0, ft_strlen(split[0]));
	else
        tmp = NULL;
    i = 1;
    while (split[i])
    {
        old_tmp = tmp;
        tmp = ft_strjoin(tmp, split[i]);
        free(old_tmp); // Free the old tmp after creating a new string
        i++;
    }
    // Free the split array
    free_split(split);
    return (tmp);
}

size_t	dllar_sign(char *str)
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

void	init_ji(int *j, size_t *i, int *start)
{
	*j = 0;
	*i = -1;
	*start = -1;
}

void	ft_splt_cmls_if(int *comillad, int *comillas, int i, char *s)
{
	if (s[i] == '"' && *comillad == 0 && *comillas == 0)
		*comillad = 1;
	else if (s[i] == '\'' && *comillad == 0 && *comillas == 0)
		*comillas = 1;
	else if (s[i] == '"' && *comillad == 1 && *comillas == 0)
		*comillad = 0;
	else if (s[i] == '\'' && *comillad == 0 && *comillas == 1)
		*comillas = 0;
}

char	**ft_splt_cmls(char const *s, char c, int comillad, int comillas)
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
	init_ji(&j, &i, &start);
	while (++i <= ft_strlen(s))
	{
		ft_splt_cmls_if(&comillad, &comillas, i, (char *)s);
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
