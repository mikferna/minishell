/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:16:45 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/24 13:57:18 by mikferna         ###   ########.fr       */
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

void	free_split(char **input)
{
	int	i;
	int	len;

	len = 0;
	while (input[len])
	{
		len++;
	}
	i = 0;
	while (i < len)
	{
		free (input[i]);
		i++;
	}
}
