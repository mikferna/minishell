/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:34:39 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/23 12:59:14 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*str_ndup(char *str, unsigned int n)
{
	char			*duped;
	unsigned int	i;

	i = 0;
	duped = malloc(sizeof(char) * (n + 1));
	while (i < n)
	{
		if (str[i] == 34 || str[i] == 39)
			i++;
		else
		{
			duped[i] = str[i];
			i++;
		}
	}
	duped[n] = 0;
	return (duped);
}

int	str_ichr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	return (-1);
}

char	*get_path_env(t_env *env)
{
	t_env	*temp;

	temp = env;
	while (temp)
	{
		if (ft_strcmp(temp->env_name, "PATH") == 0)
			return (temp->env);
		temp = temp->next;
	}
	return (NULL);
}

char	*path_join(char *path, char *bin)
{
	char	*joined;
	int		i;
	int		j;

	joined = malloc(sizeof(char) * (str_ichr(path, 0) + str_ichr(bin, 0) + 2));
	i = 0;
	j = 0;
	while (path[j])
		joined[i++] = path[j++];
	joined[i++] = '/';
	j = 0;
	while (bin[j])
		joined[i++] = bin[j++];
	joined[i] = 0;
	return (joined);
}

char	*exec_bin(char **input, t_env **env)
{
	char	*path;
	char	*dir;
	char	*bin;

	path = get_path_env(*env);
	while (path && str_ichr(path, ':') > -1)
	{
		dir = str_ndup(path, str_ichr(path, ':'));
		bin = path_join(dir, input[0]);
		free(dir);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += str_ichr(path, ':') + 1;
	}
	return (input[0]);
}
