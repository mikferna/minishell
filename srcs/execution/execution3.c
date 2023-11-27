/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:00:52 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/27 12:42:15 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	redir_here_document(char **input, t_env **env, int i)
{
	int		fd;
	int		diff;
	char	*line;

	diff = 1;
	fd = open(".temp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		g_error_num = 1;
	else
	{
		write(1, "> ", 1);
		while (get_next_line(0, &line) && line && g_error_num != 130)
		{
			if (ft_strcmp(line, input[i + 1]) == 0)
				break ;
			ft_putstr_fd(line, fd);
			ft_putstr_fd("\n", fd);
			free(line);
			write(1, "> ", 1);
		}
		(*env)->data->input_cpy = change_heredoc((*env)->data->input_cpy);
		close(fd);
	}
	return (0);
}

int	redir_append(char **input, t_env **env, int i)
{
	int	fd;

	if (ft_strcmp(input[0], ">>") != 0)
	{	
		free((*env)->data->input_cpy);
		(*env)->data->input_cpy = obtener_input(input, ">>");
		}
	fd = open(input[i + 1], O_CREAT | O_WRONLY | O_APPEND, 0644);
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

void	execution(char **input, t_env **env)
{
	if (ft_strcmp(input[0], "echo") == 0)
		g_error_num = mini_echo(*env, input, 0, 1);
	else if (ft_strcmp(input[0], "cd") == 0)
		g_error_num = cd(*env, input);
	else if (ft_strcmp(input[0], "pwd") == 0)
		g_error_num = pwd(input);
	else if (ft_strcmp(input[0], "export") == 0)
		g_error_num = export(*env, input);
	else if (ft_strcmp(input[0], "unset") == 0)
		g_error_num = unset(env, input);
	else if (ft_strcmp(input[0], "env") == 0)
		g_error_num = envi(*env, input);
	else if (ft_strcmp(input[0], "exit") == 0)
		g_error_num = exitt(input);
	else
		exec_cmd(input, env);
}
