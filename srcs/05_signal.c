/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 11:28:49 by jumoncad          #+#    #+#             */
/*   Updated: 2023/11/03 14:03:33 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	restore_prompt()
{
	g_global.error_num = 130;
	write(1, "\n", 1);
	//rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

/* void	ctrl_c(int sig)
{
	g_global.error_num = 130;
	write(1, "\n", 1);
	(void)sig;
} */

void	back_slash()
{
	g_global.error_num = 131;
	printf("Quit (core dumped)\n");
}

void run_singl(int num)
{
	if (num == 1)
	{
		signal(SIGINT, restore_prompt);
		signal(SIGQUIT, SIG_IGN);
	}
	/* if (num == 2)
	{
		signal(SIGINT, ctrl_c);
		signal(SIGQUIT, back_slash);
	} */
	if (num == 3)
	{
		ft_putstr_fd("exit\n", 1);
		exit(130);
	}
}

