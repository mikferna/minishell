/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:34:39 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/06 13:31:34 by mikferna         ###   ########.fr       */
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

void	exec_cmd(char **input, t_env **env)
{
	char	*path;
	pid_t	pid;
	int		fd[2];
	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		path = exec_bin(input, env);
		if (execve(path, input, NULL) == -1)
		{
			printf("minishell: %s: command not found\n", input[0]);
			exit(1);
		}
	}
	else
		waitpid(pid, NULL, 0);
	/* 	printf("input[0]: %s\n", input[0]);
		path = exec_bin(input, env);
		if (!path)
			exit(1);
		execve(path, input, NULL); */
}

void	execution(char **input, t_env **env)
{
	printf("input[0]: [%s]\n", input[0]);
	if (ft_strcmp(input[0], "echo") == 0)
		mini_echo(*env, input);
	else if (ft_strcmp(input[0], "cd") == 0)
		cd(*env, input);
	else if (ft_strcmp(input[0], "pwd") == 0)
		pwd(input);
	else if (ft_strcmp(input[0], "export") == 0)
		export(*env, input);
	else if (ft_strcmp(input[0], "unset") == 0)
		unset(env, input);
	else if (ft_strcmp(input[0], "env") == 0)
		envi(*env, input);
	else if (ft_strcmp(input[0], "exit") == 0)
		exitt(input);
	else
		exec_cmd(input, env);
}
