/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:44:43 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/18 11:55:06 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//me llega en el arg en el 0 export y en ls proximos me llega la variable entera, con el igual y todo, ejemp: HOLA=ADIOS
int	export(t_env **env, char **args)
{
	t_env	*temp;
	int		ret;

	temp = *env;
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
		ret = do_export(temp, args);
	if (ret == 1)
		ft_putstr_fd("failed export\n", 2);
	return (ret);
}

int	do_export(t_env *temp, char **args)
{
	char	*name;
	char	*path;
	int		i;

	i = 1;
	while (args[i])
	{
		printf("%i = [%s]\n", i, args[i]);
		name = start_strchar(args[i], '=');
		path = end_strchar(args[i], '=');
		printf("name = [%s]\n", name);
		printf("path = [%s]\n", path);
		if (!name || !path)
			return (1);
		env_addback(temp, path, name);
		//free (name);
		//free (path);
		i++;
	}
	printf("LLEGO\n");
	return (0);
}
