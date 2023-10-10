/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:09:00 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/09 15:56:55 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	exitt(char **args)
{
	if (!args[1])
	{
		printf("exit\n");
		return (0);
	}
	if (args[1] && args[2])
	{
		printf("exit\nminishell: exit: too many arguments");
		return (1);
	}
	return (ft_atoi(args[1]));
}
