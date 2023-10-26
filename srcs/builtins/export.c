/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:44:43 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/19 10:54:08 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//me llega en el arg en el 0 export y en ls proximos me llega la variable entera, con el igual y todo, ejemp: HOLA=ADIOS
int	export(t_env *env, char **args)
{
	int		ret;
	t_env	*temp;

	temp = env;
	if (!args[1])
	{
		while (temp)
		{
			printf("declare -x %s=\"%s\"\n", temp->env_name, temp->env);
			temp = temp->next;
		}
		return (1);
	}
	else
		ret = do_export(env, temp, args);
	if (ret == 1)
		ft_putstr_fd("failed export\n", 2);
	return (ret);
}

int	do_export(t_env *env, t_env	*temp, char **args)
{
	char	*name;
	char	*path;
	int		i;
	int		x;

	temp = env;
	i = 1;
	while (args[i])
	{
		x = 0;
		name = start_strchar(args[i], '=');
		path = end_strchar(args[i], '=');
		if (!name || !path)
			return (1);
		while (temp)
		{
			if (ft_strcmp(temp->env_name, name) == 0)
			{
				free(temp->env);
				temp->env = path;
				x = 1;
			}
			temp = temp->next;
		}
		temp = env;
		if (x == 0)
			env_addback(temp, path, name);
		i++;
	}
	return (0);
}
