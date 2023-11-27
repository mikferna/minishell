/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:49:55 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/27 12:21:28 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	pwd(char **args)
{
	char	*pwd;

	args = NULL;
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		ft_putstr_fd("Error in PWD\n", 2);
		return (1);
	}
	else
	{
		//aqui
		ft_putstr_fd(pwd, 1);
		write (1, "\n", 1);
		free(pwd);
	}
	return (0);
}
