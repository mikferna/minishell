/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:13:23 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/13 13:48:41 by jumoncad         ###   ########.fr       */
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

void ft_redir(t_ldata *line, t_env **env)
{
	int		i;
	//char	**input;

	i = 0;
	//input = ft_split_comillas(line->inp_line, ' ');
	line->input_cpy = ft_split_comillas(line->inp_line, ' ');
	while (line->input_cpy[i])
	{
		if (ft_strncmp(line->input_cpy[i], ">", 1) == 0)
		{
			redir_out(line->input_cpy, env, i);
			i = 0;
		}
			//redir_out(line->input_cpy, env, i);
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
	printf("stdout_cpy = %d\n", line->stdout_cpy);
	dup2(line->stdout_cpy, STDOUT_FILENO);
	//mclose(line->stdout_cpy);
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
