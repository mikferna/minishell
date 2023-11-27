/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:44:43 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/27 11:14:53 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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

t_env	*ft_temp_aux(t_env *temp, char *name, char *path, int x)
{
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
	return (temp);
}

int	do_export(t_env *env, t_env *temp, char **args)
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
		temp = ft_temp_aux(temp, name, path, x);
		temp = env;
		if (x == 0)
			env_addback(temp, path, name, env->data);
		//aqui
		free(name);
		free(path);
		i++;
	}
	return (0);
}
