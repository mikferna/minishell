/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:49:55 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/09 16:01:00 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	pwd(char **args)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd || args[1])
	{
		printf("Error in PWD\n");
		return (1);
	}
	else
		printf("%s\n", pwd);
	return (0);
}
