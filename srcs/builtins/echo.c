/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:57:09 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/11 14:31:44 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	mini_echo(t_env *env, char **args)
{
	int	n;
	int	i;

	n = 0;
	i = 1;
	if (args[1] && args[1][0] == '-')
	{
		n = 1;
		while (args[1][i])
		{
			if(args[1][i] != 'n')
				n = 0;
			i++;
		}
	}
	i = n + 1;
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (n == 0)
		write(1, "\n", 1);
	return (0);
}
