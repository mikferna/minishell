/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_ft_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:30:23 by jumoncad          #+#    #+#             */
/*   Updated: 2023/11/29 13:37:25 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_pre_redir(char *pipe, t_ldata *line, t_env **env)
{
	char	**splt_comillas;

	pipe = procesar_redirecciones(pipe, ft_strlen(pipe), NULL);
	splt_comillas = ft_splt_cmls(pipe, ' ', 0, 0);
	line->input_cpy = expander(*env, splt_comillas, 0);
	free(pipe);
	return (splt_comillas);
}

void	ft_redir(t_ldata *line, t_env **env, char *pipe, int i)
{
	char	**splt_comillas;

	splt_comillas = ft_pre_redir(pipe, line, env);
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
			i = redir_here_document(line->input_cpy, env, i, 1);
		i++;
	}
	execution(line->input_cpy, env);
	dup2((*env)->data->stdout_cpy, STDOUT_FILENO);
	dup2((*env)->data->stdin_cpy, STDIN_FILENO);
	close((*env)->data->stdout_cpy);
	close((*env)->data->stdout_cpy);
	free_split(splt_comillas);
}
