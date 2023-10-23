/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:13:23 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/23 14:00:44 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	minishell(t_ldata *line, t_env *env)
{
	(void)line;
	//(void)env;
	char *hola[4];
	hola[0] = "echo";
	hola[1] = "'hola \" $USER'";
	hola[2] = "adios";
	hola[3] = NULL;
	expander(env, hola);
	//pwd(NULL);
}
