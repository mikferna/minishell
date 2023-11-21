/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:35:45 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/20 16:27:01 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//entra el env, y en args entra 0-unset 1-la variable a hacer unset
int unset(t_env **env, char **args)
{
	t_env   *temp;
	t_env   *temp2;
	int     i;
	int     x;
	i = 1;
	temp = *env;
	temp2 = NULL;
	while (args[i])
	{
		x = 0;
		while (temp)
		{
			if (ft_strcmp(temp->env_name, args[i]) == 0)
				do_unset(env, temp, temp2, x);
			x++;
			temp2 = temp;
			temp = temp->next;
		}
		temp = *env;
		i++;
	}
	return (0);
}
void do_unset(t_env **env, t_env *temp, t_env *temp2, int x)
{
	if (x == 0)
		*env = temp->next;
	else
		temp2->next = temp->next;
}
