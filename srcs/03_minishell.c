/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:13:23 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/17 13:45:09 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	minishell(t_ldata *line, t_env *env)
{
	(void)line;
	//(void)env;
	char *hola[4];
	hola[0] = "export";
	hola[1] = "HOLA=ADIOS";
	hola[2] = "ADIOS=HOLA";
	hola[3] = NULL;
    char *args[2];
	args[0] = "env";
	args[1] = NULL;
	export(&env, hola);
	envi(env, args);
	//mini_echo(env, args);
	//pwd(NULL);
}
