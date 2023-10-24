/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:59:02 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/18 12:32:44 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_ldata	*line;
	t_env	*env;
	int		check;

	if (argc != 1 || argv[1])
	{
		printf("This program does not accept arguments\n");
		exit(1);
	}
	init_structs(&line, &env, envp);
	while (1)
	{
		line->inp_line = readline("miñishell> ");
		check = check_line_quote(line);
		if (check >= 1)
		{
			if (check == 1)
				printf("Input Error\n");
			continue ;
		}
		if (*line->inp_line != 0)
			add_history(line->inp_line);
		else
			continue ;
		minishell(line, env);
	}
	return (0);
}

void	init_structs(t_ldata **line, t_env **env, char **envp)
{
	*line = malloc(sizeof(t_ldata));
	get_env(envp, env);
}

void prueba()
{
	printf("prueba\n");
}
