/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:16:45 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/28 11:39:37 by mikferna         ###   ########.fr       */
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
	if (!s1 || !s2)
		return (-1);
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		i++;
	}
	return (1);
}

void	free_split(char **arr)
{
	int	i;

	if (arr == NULL)
		return ;
	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_doublesize2(const char *s, char c)
{
	int		size;
	int		comillad;
	int		comillas;
	size_t	i;

	size = 0;
	comillad = 0;
	comillas = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '"' && comillad == 0 && comillas == 0)
			comillad = 1;
		else if (s[i] == '\'' && comillad == 0 && comillas == 0)
			comillas = 1;
		else if (s[i] == '"' && comillad == 1 && comillas == 0)
			comillad = 0;
		else if (s[i] == '\'' && comillad == 0 && comillas == 1)
			comillas = 0;
		else if ((s[i] == c || s[i + 1] == '\0') && comillad == 0
			&& comillas == 0)
			size++;
		i++;
	}
	return (size);
}
