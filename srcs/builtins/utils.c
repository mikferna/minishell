/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:16:45 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/23 11:53:44 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_path(t_env *env, char *dir)
{
	while (env)
	{
		if (ft_strcmp(env->env_name, dir) == 0)
			return (env->env);
		env = env->next;
	}
	return (NULL);	
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return (s1[i] - s2[i]);
}

/* char	**ft_split_comillas_dobles(char const *s, char c)
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
		else if (start >= 0 && (s[i] == c || i == ft_strlen(s)) && (comillad == 0 || comillas == 0))
		{
			result[j++] = ft_substr(s, start, (i - start));
			start = -1;
		}
	}
	result[j] = NULL;
	return (result);
} */
