/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:09:00 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/29 12:35:40 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_digit2(char *arg)
{
	int	n;

	n = 0;
	while (arg[n])
	{
		if (arg[n] >= '0' && arg[n] <= '9')
			n++;
		else
			return (1);
	}
	return (0);
}

int	exitt(char **args)
{
	if (args[1] && is_digit2(args[1]))
	{
		ft_putstr_fd("exit\npipehell: exit: : numeric argument required\n"\
					, 2);
		exit(255);
	}
	if (!args[1])
	{
		ft_putstr_fd("exit\n", 2);
		exit (0);
	}
	if (args[1] && args[2])
	{
		ft_putstr_fd("pipehell: exit too many arguments\n", 2);
		exit (-358);
	}
	else
	{
		ft_putstr_fd("exit\n", 2);
		exit (ft_atoi(args[1]));
	}
	return (ft_atoi(args[1]));
}
