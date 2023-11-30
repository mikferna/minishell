/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:58:42 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/30 11:55:50 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_cmd(char **input, t_env **env, char *path)
{
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
		if (execve(path, input, (*env)->data->envp) == -1
			&& ft_strcmp(input[0], ">") != 0)
		{
			ft_putstr_fd("minishell: ", (*env)->data->stdout_cpy);
			ft_putstr_fd(input[0], (*env)->data->stdout_cpy);
			ft_putstr_fd(": command not found\n", (*env)->data->stdout_cpy);
			exit(127);
		}
	}
	else
	{
		waitpid(pid, &g_error_num, 0);
		g_error_num = WEXITSTATUS(g_error_num);
	}
}

void	obtener_input(char **input, char *c)
{
	int		x;
	int		i;

	x = 0;
	while (ft_strcmp(input[x], c) != 0)
		x++;
	i = x;
	x += 2;
	while (input[x])
	{
		free(input[i]);
		input[i] = ft_strdup(input[x]);
		x++;
		i++;
	}
	free(input[x - 1]);
	free(input[x - 2]);
	input[i] = NULL;
}

int	redir_out(char **input, t_env **env, int i)
{
	int	fd;

	(void)env;
	fd = open(input[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (ft_strcmp(input[0], ">") != 0)
		obtener_input(input, ">");
	if (fd < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(input[i + 1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_error_num = 1;
	}
	else
	{
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	return (0);
}

int	redir_in(char **input, t_env **env, int i)
{
	int	fd;

	(void)env;
	if (ft_strcmp(input[0], "<") != 0)
		obtener_input(input, "<");
	fd = open(input[i + 1], O_RDONLY, 0644);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(input[i + 1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_error_num = 1;
	}
	else
	{
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	return (0);
}

char	**change_heredoc(char **original)
{
	int	i;

	i = 0;
	while (original[i])
	{
		if (ft_strcmp(original[i], "<<") == 0)
		{
			free(original[i]);
			original[i] = ft_strdup("<");
			free(original[i + 1]);
			original[i + 1] = ft_strdup(".temp");
			break ;
		}
		i++;
	}
	return (original);
}
