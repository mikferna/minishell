/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 13:13:23 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/26 13:05:00 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	minishell(t_ldata *line, t_env *env)
{
	(void)line;
	//(void)env;
	char **hola;
	int i = 0;
	/* hola[0] = "echo";
	hola[1] = "hola\"simon\"\"\"\"\"\"\"\"\"\"\"\"\"\"volibar";
	hola[2] = "adios";
	hola[3] = NULL; */
	hola = ft_split(line->inp_line, ' ');
	g_global.error_num = 0;
	while (hola[i])
	{
		printf("%s\n", hola[i]);
		i++;
	}
	expander(env, hola);
	i = 0;
	while (hola[i])
	{
		printf("%s\n", hola[i]);
		i++;
	}
	//pwd(NULL);
}
