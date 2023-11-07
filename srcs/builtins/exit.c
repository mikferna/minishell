/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:09:00 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/07 14:19:54 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//entra en el 0-exit 1-un numero 2+-nada o si entra algo va a dar mal
int	exitt(char **args)
{
	if (!args || !args[1])
	{
		ft_putstr_fd("exit\n", 2);
		exit (0);
	}
	if (args[0] && args[1])
	{
		ft_putstr_fd("exit\nminishell: exit: too many arguments\n", 2);
		exit (1);
	}
	return (ft_atoi(args[1]));
}
