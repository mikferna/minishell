/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:35:45 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/19 11:55:38 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//entra el env, y en args entra 0-unset 1-la variable a hacer unset
int	unset(t_env *env, char **args)
{
	t_env	*temp;
	t_env	*temp2;
	int		i;
	int		x;

	i = 1;
	temp = env;
	temp2 = NULL;
	while (args[i])
	{
		x = 0;
		while (temp)
		{
			if (ft_strcmp(temp->env_name, args[i]) == 0)
				do_unset(temp, temp2, env, x);
			x++;
			temp2 = temp;
			temp = temp->next;
		}
		temp = env;
		i++;
	}
	return (0);
}

void	do_unset(t_env *temp, t_env *temp2, t_env *env, int x)
{
	if (x == 0)
		env = env->next;
	else
		temp2->next = temp->next;
}
