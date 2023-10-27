/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:21:44 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/18 13:23:05 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	get_env(char **envp, t_env **env)
{
	int		i;
	t_env	*temp;

	*env = ft_lstnew(end_strchar(envp[0], '='), start_strchar(envp[0], '='));
	temp = *env;
	i = 1;
	while (envp[i])
	{
		env_addback(temp, end_strchar(envp[i], '='), start_strchar(envp[i], '='));
		i++;
	}
}
 