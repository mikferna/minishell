/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 12:58:42 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/27 12:20:06 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
		g_error_num = execve(path, input, (*env)->data->envp);
		if (g_error_num == -1 && ft_strcmp(input[0], ">") != 0)
		{
			g_error_num = 1;
			ft_putstr_fd("minishell: ", (*env)->data->stdout_cpy);
			ft_putstr_fd(input[0], (*env)->data->stdout_cpy);
			ft_putstr_fd(": command not found\n", (*env)->data->stdout_cpy);
			exit(127);
		}
	}
	else
		waitpid(pid, NULL, 0);
}

char	**obtener_input(char **input, char *c)
{
	int		x;
	char	**input2;
	int		i;

	x = 0;
	i = 0;
	while (input[i])
		i++;
	//aqui
	input2 = malloc(sizeof(char *) * (i));
	while (ft_strcmp(input[x], c) != 0)
	{
		input2[x] = ft_strdup(input[x]);
		x++;
	}
	i = x;
	x += 2;
	while (input[x])
	{
		input2[i] = ft_strdup(input[x]);
		x++;
		i++;
	}
	input2[i] = NULL;
	return (input2);
}

int	redir_out(char **input, t_env **env, int i)
{
	int	fd;

	if (ft_strcmp(input[0], ">") != 0)
		(*env)->data->input_cpy = obtener_input(input, ">");
	fd = open(input[i + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
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

	if (ft_strcmp(input[0], "<") != 0)
		(*env)->data->input_cpy = obtener_input(input, "<");
	fd = open(input[i + 1], O_RDONLY, 0644);
	printf("fd: %d\n", fd);
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

char	**change_heredoc(char	**original)
{
	int		i;

	i = 0;
	while (original[i])
	{
		if (ft_strcmp(original[i], "<<") == 0)
		{
			//aqui
			//free(original[i]);
			original[i] = ft_strdup("<");
			//free(original[i + 1]);
			original[i + 1] = ft_strdup(".temp");
			break ;
		}
		i++;
	}
	return (original);
}
