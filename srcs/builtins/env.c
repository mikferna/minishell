/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:20:16 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/27 11:02:27 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	envi(t_env *env, char **args)
{
	t_env	*temp;

	temp = env;
	if (args[1])
	{
		ft_putstr_fd("env: ", 2);
		ft_putstr_fd(args[1], 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (127);
	}
	while (temp)
	{
		printf("%s=%s\n", temp->env_name, temp->env);
		temp = temp->next;
	}
	return (0);
}
