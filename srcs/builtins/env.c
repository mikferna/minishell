/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:20:16 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/06 12:11:48 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	env(t_env *env, char **args)
{
	t_env	*temp;

	temp = env;
	if (args[1])
	{
		printf("env: %s: No such file or directory", args[1]);
		return (1);
	}
	while (temp)
	{
		printf("%s=\"%s\"\n", temp->env_name, temp->env);
		temp = temp->next;
	}
	return (0);
}
