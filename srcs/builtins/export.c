/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:44:43 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/11 13:59:16 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//me llega en el arg en el 0 unset y en ls proximos me llega la variable entera, con el igual y todo, ejemp: HOLA="ADIOS"
int	export(t_env *env, char **args)
{
	t_env	*temp;
	int		ret;

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
		ret = do_export(&env, args);
	if (ret == 1)
		ft_putstr_fd("failed export", 2);
	return (ret);
}

int	do_export(t_env **env, char **args)
{
	t_env	**temp;
	char	*name;
	char	*path;
	int		i;

	temp = env;
	i = 0;
	while (args[i])
	{
		name = start_strchar(args[i], '=');
		path = end_strchar(args[i], '=');
		if (!name || !path)
			return (1);
		env_addback(*env, path, name);
		free (name);
		free (path);
		i++;
	}
	return (0);
}
