/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:11:51 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/31 15:44:35 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//aqui entra el env y como args 1-cd 2-lo que venga o vacio
int	cd(t_env *env, char **args)
{
	int	i;

	i = 0;
	if (!args[1] || args[1][0] == '~')
		i = home_cd(env);
	else if (args[1][0] == '/' && args[1][1] == '\0')
		i = s_case(env);
	else if (args[1])
		i = absolute_path(env, args[1]);
	else if (args[1][0] == '.' && args[1][1] == '.')
		i = go_back(env);
	else if (args[1][0] == '.')
		i = do_nothing();
	return (i);
}

int	home_cd(t_env *env)
{
	char	*h;
	char	*h_path;
	char	n_cwd[8500];
	char	o_cwd[8500];

	h = "HOME";
	h_path = get_path(env, h);
	getcwd(o_cwd, sizeof(o_cwd));
	if (chdir(h_path) == 0)
	{
		getcwd(n_cwd, sizeof(n_cwd));
		update_pwd("PWD", env, n_cwd);
		update_pwd("OLDPWD", env, o_cwd);
	}
	else
	{
		printf("cd: HOME not set\n");
		printf("Chdir failed in home_cd\n");
		return (1);
	}
	return (0);
}

int	s_case(t_env *env)
{
	char	n_cwd[8500];
	char	o_cwd[8500];
	getcwd(o_cwd, sizeof(o_cwd));
	if (chdir("/") == 0)
	{
		getcwd(n_cwd, sizeof(n_cwd));
		update_pwd("PWD", env, n_cwd);
		update_pwd("OLDPWD", env, o_cwd);
	}
	else
	{
		if (access("/", F_OK) == -1)
			printf("no such file or directory: ");
		else if (access("/", R_OK) == -1)
			printf("permission denied: ");
		printf("Chdir failed in s_case\n");
		return (1);
	}
	return (0);
}
int	go_back(t_env *env)
{
	char	n_cwd[8500];
	char	o_cwd[8500];
	getcwd(o_cwd, sizeof(o_cwd));
	if (chdir("..") == 0)
	{
		getcwd(n_cwd, sizeof(n_cwd));
		update_pwd("PWD", env, n_cwd);
		update_pwd("OLDPWD", env, o_cwd);
	}
	else
	{
		if (access("..", F_OK) == -1)
			printf("no such file or directory: ");
		else if (access("..", R_OK) == -1)
			printf("permission denied: ");
		printf("Chdir failed in go_back\n");
		return (1);
	}
	return (0);
}

void	update_pwd(char *name, t_env *env, char *path)
{
	t_env	*temp;

	temp = env;
	while (temp)
	{
		if (ft_strcmp(temp->env_name, name) == 0)
		{
			//free (temp->env);
			temp->env = path;
			break ;
		}
		temp = temp->next;
	}
}
