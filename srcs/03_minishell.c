/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:13:23 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/27 12:48:17 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_aux_procesar_redirecciones(const char *cadena, char *ptr)
{
	while (*cadena != '\0')
	{
		if (*cadena == '<' || *cadena == '>')
		{
			*ptr = ' ';
			ptr++;
			*ptr = *cadena;
			ptr++;
			if (*(cadena + 1) == *cadena)
			{
				*ptr = *cadena;
				ptr++;
				cadena++;
			}
			*ptr = ' ';
			ptr++;
		}
		else
		{
			*ptr = *cadena;
			ptr++;
		}
		cadena++;
	}
	*ptr = '\0';
}

char	*procesar_redirecciones(const char *cadena, size_t len, char *ptr)
{
	char	*cadena_modificada;

	cadena_modificada = (char *)malloc((len * 3 + 1) * sizeof(char));
	if (cadena_modificada == NULL)
		exit(EXIT_FAILURE);
	ptr = cadena_modificada;
	ft_aux_procesar_redirecciones(cadena, ptr);
	return (cadena_modificada);
}

void	ft_redir(t_ldata *line, t_env **env, char *pipe)
{
	int		i;
	char	**splt_comillas;

	i = 0;
	pipe = procesar_redirecciones(pipe, ft_strlen(pipe), NULL);
	splt_comillas = ft_splt_cmls(pipe, ' ', 0, 0);
	line->input_cpy = expander(*env, splt_comillas, NULL, 0);
	free(pipe);
	(*env)->data->stdout_cpy = dup(STDOUT_FILENO);
	(*env)->data->stdin_cpy = dup(STDIN_FILENO);
	while (line->input_cpy && line->input_cpy[0] && line->input_cpy[i])
	{
		if (ft_strncmp(line->input_cpy[i], ">", 2) == 0)
			i = redir_out(line->input_cpy, env, i);
		else if (ft_strncmp(line->input_cpy[i], ">>", 2) == 0)
			i = redir_append(line->input_cpy, env, i);
		else if (ft_strncmp(line->input_cpy[i], "<", 2) == 0)
			i = redir_in(line->input_cpy, env, i);
		else if (ft_strncmp(line->input_cpy[i], "<<", 2) == 0)
			i = redir_here_document(line->input_cpy, env, i);
		i++;
	}
	if (g_error_num != 1)
		execution(line->input_cpy, env);
	dup2((*env)->data->stdout_cpy, STDOUT_FILENO);
	dup2((*env)->data->stdin_cpy, STDIN_FILENO);
	close((*env)->data->stdout_cpy);
	close((*env)->data->stdout_cpy);
	free_split(splt_comillas);
	// Free memory allocated for line->input_cpy
    if (line->input_cpy) {
        for (i = 0; line->input_cpy[i]; i++)
            free(line->input_cpy[i]);
        free(line->input_cpy);
    }
}

void	ft_aux_pipe(t_ldata *line, t_env **env, int i)
{
	pid_t	pid;

	if (pipe(line->pipe_fd) == -1)
		perror("pipe");
	pid = fork();
	if (pid == 0)
	{
		dup2(line->prev_pipe, STDIN_FILENO);
		if (line->split_pipes[i + 1])
			dup2(line->pipe_fd[1], STDOUT_FILENO);
		close(line->pipe_fd[0]);
		line->input = ft_splt_cmls(line->split_pipes[i], ' ', 0, 0);
		line->input = expander(*env, line->input, NULL, 0);
		if (line->input[0] && ft_strncmp(line->input[0], "	", 1) != 0)
			ft_redir(line, env, line->split_pipes[i]);
		if (line->input)
		{
			for (i = 0; line->input[i]; i++)
				free(line->input[i]);
			free(line->input);
		}
		exit(EXIT_SUCCESS);
	}
	else if (pid > 0)
	{
		wait(NULL);
		close(line->pipe_fd[1]);
		line->prev_pipe = line->pipe_fd[0];
	}
	else
		perror("fork");
}

void	minishell(t_ldata *line, t_env **env)
{
	int	i;

	line->prev_pipe = STDIN_FILENO;
	i = 0;
	line->split_pipes = ft_splt_cmls(line->inp_line, '|', 0, 0);
	run_singl(2);
	while (line->split_pipes[i])
	{
		if (line->split_pipes[1])
			ft_aux_pipe(line, env, i);
		else
		{
			line->input = ft_splt_cmls(line->split_pipes[i], ' ', 0, 0);
			line->input = expander(*env, line->input, NULL, 0);
			if (line->input[0] && ft_strncmp(line->input[0], "	", 1) != 0)
				ft_redir(line, env, line->split_pipes[i]);
		}
		i++;
	}
	// Free memory allocated for line->input and line->split_pipes
    if (line->input) {
        for (i = 0; line->input[i]; i++)
            free(line->input[i]);
        free(line->input);
    }
    if (line->split_pipes) {
        for (i = 0; line->split_pipes[i]; i++)
            free(line->split_pipes[i]);
        free(line->split_pipes);
    }
}
