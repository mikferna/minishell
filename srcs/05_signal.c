/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:28:49 by jumoncad          #+#    #+#             */
/*   Updated: 2023/11/24 11:43:28 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	restore_prompt(int sig)
{
	g_error_num = 130;
	write(1, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
	(void)sig;
}

void	ctrl_c(int sig)
{
	g_error_num = 130;
	write(1, "\n", 1);
	(void)sig;
}

void	back_slash(int sig)
{
	g_error_num = 131;
	printf("Quit: 3\n");
	(void)sig;
}

void	run_singl(int num)
{
	if (num == 1)
	{
		signal(SIGINT, restore_prompt);
		signal(SIGQUIT, SIG_IGN);
	}
	if (num == 2)
	{
		signal(SIGINT, ctrl_c);
		signal(SIGQUIT, back_slash);
	}
	if (num == 3)
	{
		ft_putstr_fd("exit\n", 1);
		exit(130);
	}
}
