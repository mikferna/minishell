/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 14:02:50 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/04 14:17:25 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	absolute_path(t_env *env, char *path)
{
	char	n_cwd[8500];
	char	o_cwd[8500];
	getcwd(o_cwd, sizeof(o_cwd));
	if (chdir(path) == 0)
	{
		getcwd(n_cwd, sizeof(n_cwd));
		update_pwd("PWD", env, n_cwd);
		update_pwd("OLDPWD", env, o_cwd);
	}
	else
	{
		if (access(path, F_OK) == -1)
			printf("no such file or directory: ");
		else if (access(path, R_OK) == -1)
			printf("permission denied: ");
		printf("Chdir failed in absolute_path\n");
		return (1);
	}
	return (0);
}

int	do_nothing(void)
{
	if (chdir(".") == 0)
		return (0);
	else
	{
		if (access(".", F_OK) == -1)
			printf("no such file or directory: ");
		else if (access(".", R_OK) == -1)
			printf("permission denied: ");
		printf("Chdir failed in do_nothing\n");
		return (1);
	}
	return (0);
}
