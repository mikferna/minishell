/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:34:39 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/03 13:10:10 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	execution(char **input, t_env **env)
{
	if (ft_strcmp(input[0], "echo") == 0)
		mini_echo(*env, input);
	else if (ft_strcmp(input[0], "cd") == 0)
		cd(*env, input);
	else if (ft_strcmp(input[0], "pwd") == 0)
		pwd(input);
	else if (ft_strcmp(input[0], "export") == 0)
		export(*env, input);
	else if (ft_strcmp(input[0], "unset") == 0)
		unset(env, input);
	else if (ft_strcmp(input[0], "env") == 0)
		envi(*env, input);
	else if (ft_strcmp(input[0], "exit") == 0)
		exitt(input);
}