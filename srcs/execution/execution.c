/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:34:39 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/10 14:02:37 by mikferna         ###   ########.fr       */
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
		if ((*env)->data->envp)
			printf("(*env)->data->envp: %s\n", (*env)->data->envp[0]);
		if (execve(path, input, (*env)->data->envp) == -1)
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

void redir_out(char **input, t_env **env, int i)
{
	int fd;
	int stdout_cpy;
	fd = open(input[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(input[i + 1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
	}
	else
	{
		printf("env->env: %s\n", (*env)->env_name);
		stdout_cpy = dup(STDOUT_FILENO);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		exec_cmd(input, env);
		dup2(stdout_cpy, STDOUT_FILENO);
		close(stdout_cpy);
	}
}

void	execution(char **input, t_env **env)
{
	if (ft_strcmp(input[0], "echo") == 0)
		g_global.error_num = mini_echo(*env, input);
	else if (ft_strcmp(input[0], "cd") == 0)
		g_global.error_num = cd(*env, input);
	else if (ft_strcmp(input[0], "pwd") == 0)
		g_global.error_num = pwd(input);
	else if (ft_strcmp(input[0], "export") == 0)
		g_global.error_num = export(*env, input);
	else if (ft_strcmp(input[0], "unset") == 0)
		g_global.error_num = unset(env, input);
	else if (ft_strcmp(input[0], "env") == 0)
		g_global.error_num = envi(*env, input);
	else if (ft_strcmp(input[0], "exit") == 0)
		g_global.error_num = exitt(input);
	else
		exec_cmd(input, env);
}
