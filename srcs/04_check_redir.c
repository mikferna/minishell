/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_check_redir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 11:54:21 by jumoncad          #+#    #+#             */
/*   Updated: 2023/11/24 12:02:49 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_stdin(char *s, int k)
{
	if (s[k + 1] == ' ' && s[k + 2] == '\0')
		return (1);
	if (s[k + 1] == ' ' && s[k + 2] != '\0')
		return (0);
	if (s[k + 1] == ' ')
		return (0);
	if (s[k + 1] == '>' && (s[k + 2] == '>' || s[k + 2] == '<' || s[k
			+ 2] == '|'))
		return (1);
	else if (s[k + 1] == '<' || s[k + 1] == '|' || s[k + 1] == '\0' || s[k
		+ 1] == ' ')
		return (1);
	return (0);
}

int	check_stdout(char *s, int k)
{
	if (s[k + 1] == ' ' && s[k + 2] == '\0')
		return (1);
	if (s[k + 1] == ' ' && s[k + 2] != '\0')
		return (0);
	if (s[k + 1] == ' ')
		return (0);
	if (s[k + 1] == '<' && (s[k + 2] == '>' || s[k + 2] == '<' || s[k
			+ 2] == '|'))
		return (1);
	else if (s[k + 1] == '>')
		return (1);
	else if (s[k + 1] == '|' || s[k + 1] == ' ' || s[k + 1] == '\0')
		return (1);
	return (0);
}

int	check_pipe(char *s, int k)
{
	if (s[k + 1] == ' ' && s[k + 2] == '\0')
		return (1);
	if (s[k + 1] == ' ' && s[k + 2] != '\0')
		return (0);
	if (s[k + 1] == '>' && (s[k + 2] == '>' || s[k + 2] == '<' || s[k
			+ 2] == '|'))
		return (1);
	if (s[k + 1] == '\0')
		return (1);
	return (0);
}

int	check_aux(char *s, int k)
{
	while (s[k] == '>' || s[k] == '<' || s[k] == '|')
	{
		if (s[k] == '>')
		{
			if (check_stdin(s, k) != 0)
				return (1);
		}
		else if (s[k] == '<')
		{
			if (check_stdout(s, k) != 0)
				return (1);
		}
		else if (s[k] == '|')
		{
			if (check_pipe(s, k) != 0)
				return (1);
		}
		k++;
	}
	return (0);
}

int	ft_check_redir(char *s)
{
	int	i;
	int	k;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] == '>' || s[i] == '<' || s[i] == '|')
		{
			k = i;
			if (check_aux(s, k) != 0)
				return (1);
		}
		i++;
	}
	return (0);
}
