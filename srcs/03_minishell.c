/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:13:23 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/06 13:34:31 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	minishell(t_ldata *line, t_env **env)
{
	char	**input;

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
	input = ft_split_comillas(line->inp_line, ' ');
	input = expander(*env, input);
	if (input[0] && ft_strncmp(input[0], "	", 1) != 0)
		execution(input, env);
}
