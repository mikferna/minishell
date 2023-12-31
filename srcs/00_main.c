/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:59:02 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/24 14:12:40 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv, char **envp)
{
	t_ldata	*line;
	t_env	*env;

	if (argc != 1 || argv[1])
	{
		printf("This program does not accept arguments\n");
		exit(1);
	}
	init_structs(&line, &env, envp);
	init_minishell(line, env);
	return (0);
}

void	init_structs(t_ldata **line, t_env **env, char **envp)
{
	*line = malloc(sizeof(t_ldata));
	if (*line == NULL)
	{
		fprintf(stderr, "Error: No se pudo asignar memoria para t_ldata\n");
		exit(EXIT_FAILURE);
	}
	(*line)->input_cpy = NULL;
	(*line)->split_pipes = NULL;
	(*line)->stdout_cpy = 0;
	if (envp != NULL)
		(*line)->envp = envp;
	else
	{
		fprintf(stderr, "Error: envp es nulo\n");
		exit(EXIT_FAILURE);
	}
	get_env(envp, env, line);
}

void	init_minishell(t_ldata *line, t_env *env)
{
	int	check;

	while (1)
	{
		run_singl(1);
		line->inp_line = readline("miñishell> ");
		if (line->inp_line == NULL || ft_strcmp(line->inp_line, "exit") == 0)
			run_singl(3);
		if (line->inp_line)
		{
			check = check_line_quote(line);
			if (check == 1)
				printf("Input Error\n");
			if (*line->inp_line != 0)
				add_history(line->inp_line);
			else
				continue ;
			minishell(line, &env);
		}
	}
}
