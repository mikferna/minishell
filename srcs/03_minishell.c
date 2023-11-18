/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:13:23 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/16 12:58:27 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_redirection(t_ldata *line)
{
	int	i;
	char	**input;
	
	i = 0;
	input = ft_split_comillas(line->inp_line, ' ');
	while (input[i])
	{
		if (ft_strncmp(input[i], ">", 1) == 0)
			return (1);
		else if (ft_strncmp(input[i], ">>", 2) == 0)
			return (1);
		else if (ft_strncmp(input[i], "<", 1) == 0)
			return (1);
		else if (ft_strncmp(input[i], "<<", 2) == 0)
			return (1);
		else if (ft_strncmp(input[i], "|", 1) == 0)
			return (1);
		i++;
	}
	return (0);
}

char *procesar_redirecciones(const char *cadena, size_t len, char *ptr)
{
	char *cadena_modificada = (char *)malloc((len * 3 + 1) * sizeof(char));
	if (cadena_modificada == NULL)
		exit(EXIT_FAILURE);
	ptr = cadena_modificada;
	while (*cadena != '\0')
	{
		if ((*cadena == '<' || *cadena == '>'))
		{
			*ptr = ' ';
			ptr++;
			*ptr = *cadena;
			ptr++;
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
	return (cadena_modificada);
}

void ft_redir(t_ldata *line, t_env **env)
{
	int		i;
	//char	**input;

	i = 0;
	//funcion para dejar espacios entre redirecciones
	line->inp_line = procesar_redirecciones(line->inp_line, ft_strlen(line->inp_line), NULL);
	line->input_cpy = ft_split_comillas(line->inp_line, ' ');
	(*env)->data->stdout_cpy = dup(STDOUT_FILENO);
	while (line->input_cpy && line->input_cpy[i])
	{
		if (ft_strncmp(line->input_cpy[i], ">", 1) == 0)
		{
			redir_out(line->input_cpy, env, i);
			i = 0;
		}
/* 		else if (ft_strncmp(input[i], ">>", 2) == 0)
			redir_out(input, env, i);
		else if (ft_strncmp(input[i], "<", 1) == 0)
			redir_in(input, env, i);
		else if (ft_strncmp(input[i], "<<", 2) == 0)
			redir_in(input, env, i);
		else if (ft_strncmp(input[i], "|", 1) == 0)
			pipe(input, env, i); */
		i++;
	}
	execution(line->input_cpy, env);
	//exec_cmd(pathv2, env);
	dup2((*env)->data->stdout_cpy, STDOUT_FILENO);
	close((*env)->data->stdout_cpy);
}

void	minishell(t_ldata *line, t_env **env)
{
	char	**input;
	int		redir;

	redir = ft_redirection(line);
	if (redir == 1)
		ft_redir(line, env);
	else
	{
		input = ft_split_comillas(line->inp_line, ' ');
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
}
