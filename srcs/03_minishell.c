/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:13:23 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/18 13:07:40 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_redirection(char *line)
{
	int	i;
	char	**input;
	
	i = 0;
	input = ft_split_comillas(line, ' ');
	while (input[i])
	{
		if (ft_strnstr(input[i], ">", ft_strlen(input[i])) == 0)
			return (1);
		else if (ft_strnstr(input[i], ">>", ft_strlen(input[i])) == 0)
			return (1);
		else if (ft_strnstr(input[i], "<", ft_strlen(input[i])) == 0)
			return (1);
		else if (ft_strnstr(input[i], "<<", ft_strlen(input[i])) == 0)
			return (1);
		i++;
	}
	return (0);
}

char *procesar_redirecciones(const char *cadena, size_t len, char *ptr)
{
	char *cadena_modificada;

	cadena_modificada = (char *)malloc((len * 3 + 1) * sizeof(char));
	if (cadena_modificada == NULL)
		exit(EXIT_FAILURE);
	ptr = cadena_modificada;
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
	return cadena_modificada;
}

void ft_redir(t_ldata *line, t_env **env, char *pipe_line)
{
	int		i;

	i = 0;
	pipe_line = procesar_redirecciones(pipe_line, ft_strlen(pipe_line), NULL);
	printf("pipe_line: %s\n", pipe_line);
	line->input_cpy = expander(*env, ft_split_comillas(pipe_line, ' '));
	(*env)->data->stdout_cpy = dup(STDOUT_FILENO);
	(*env)->data->stdin_cpy = dup(STDIN_FILENO);
	while (line->input_cpy && line->input_cpy[i])
	{
		if (ft_strncmp(line->input_cpy[i], ">", 2) == 0)
			i = redir_out(line->input_cpy, env, i);
 		else if (ft_strncmp(line->input_cpy[i], ">>", 2) == 0)
			i = redir_append(line->input_cpy, env, i);
		else if (ft_strncmp(line->input_cpy[i], "<", 2) == 0)
			i = redir_in(line->input_cpy, env, i);
		//else if (ft_strncmp(line->input_cpy[i], "<<", 2) == 0)
		//	i = redir_here_document(line->input_cpy, env, i);
		i++;
	}
	execution(line->input_cpy, env);
	dup2((*env)->data->stdout_cpy, STDOUT_FILENO);
	dup2((*env)->data->stdin_cpy, STDIN_FILENO);
	close((*env)->data->stdout_cpy);
	close((*env)->data->stdout_cpy);
}

void	minishell(t_ldata *line, t_env **env)
{
	char	**input;
	int		redir;
	int		i;

	i = 0;
	line->split_pipes = ft_split_comillas(line->inp_line, '|');
	while(line->split_pipes[i])
	{
		redir = ft_redirection(line->split_pipes[i]);
		if (redir == 1)
			ft_redir(line, env, line->split_pipes[i]);
		else
		{
			input = ft_split_comillas(line->split_pipes[i], ' ');
			input = expander(*env, input);
			if (input[0] && ft_strncmp(input[0], "	", 1) != 0)
				execution(input, env);
		}
		/**
			comprobar si hay redireccion
			if (true)
			{
			if (redirection(line) == 1)
				input = expander(*env, input);
				execution(input, env);
			}
			else {
			input = ft_split_comillas(line->inp_line, ' ');
			input = expander(*env, input);
			execution(input, env);
			}
		*/
		/* input = ft_split_comillas(line->inp_line, ' ');
		input = expander(*env, input);
		if (input[0] && ft_strncmp(input[0], "	", 1) != 0)
			execution(input, env); */
		i++;
	}
}
