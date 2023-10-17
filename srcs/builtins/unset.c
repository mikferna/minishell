/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:35:45 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/11 13:15:23 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//entra el env, y en args entra 0-unset 1-la variable a hacer unset
int	unset(t_env *env, char **args)
{
	t_env	*temp;
	t_env	*temp2;
	int		i;

	i = 0;
	temp = env;
	temp2 = NULL;
	while (temp)
	{
		while (args[i])
		{
			if (ft_strcmp(temp->env_name, args[i]) == 0)
			{
				do_unset(&temp, &temp2);
				break;
			}
			i++;
		}
		i = 0;
		temp2 = temp;
		temp = temp->next;
	}
	return (0);
}

void	do_unset(t_env **env, t_env **past_env)
{
	if (*past_env)
		(*past_env)->next = (*env)->next;
	free(*env);
}
