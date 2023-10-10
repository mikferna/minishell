/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:21:44 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/04 11:39:23 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	get_env(char **envp, t_env **env)
{
	int		i;
	t_env	*temp;

	*env = ft_lstnew(start_strchar(envp[0], '='), end_strchar(envp[0], '='));
	temp = *env;
	i = 1;
	while (envp[i])
	{
		env_addback(temp, start_strchar(envp[i], '='), end_strchar(envp[i], '='));
		i++;
	}
}
 