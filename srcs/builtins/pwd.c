/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:49:55 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/11 14:37:27 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// en el 0 entra pwd y luego puede entrar cualquier cosa
int	pwd(char **args)
{
	char	*pwd;
		
	pwd = getcwd(NULL, 0);
	if (!pwd)
	{
		ft_putstr_fd("Error in PWD\n", 2);
		return (1);
	}
	else
	{
		ft_putstr_fd(pwd, 1);
		write (1, "\n", 1);
	}
	return (0);
}
