/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:02:12 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/17 13:58:26 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_line_quote(char *s)
{
	int	i;
	int	quoted;
	int	quotes;

	quotes = 0;
	quoted = 0;
	i = 0;
	if (!s)
		return (2);
	while (s && s[i])
	{
		if (s[i] == '\"')
			quoted++;
		if (s[i] == '\'')
			quotes++;
		i++;
	}
	if (check_redirections(s) == 1)
		return (1);
	if (quoted % 2 != 0 || quotes % 2 != 0)
		return (1);
	return (0);
}

int	check_redirections(char *s)
{
	int		i;
	char	**temp;

	i = 0;
	temp = ft_split(s, '\'');
	if (ft_check_redir(temp[0]) == 0)
		return (0);
	return (1);
}

int	check_stdin(char *s, int k)
{
	if (s[k + 1] == '>' && (s[k + 2] == '>' || s[k + 2] == '<' || s[k
			+ 2] == '|'))
		return (1);
	else if (s[k + 1] == '<' || s[k + 1] == '|' || s[k + 1] == '\0' || s[k
		+ 1] == ' ')
		return (1);
	else
		return (0);
	return (1);
}

int	check_stdout(char *s, int k)
{
	if (s[k + 1] == '<' && (s[k + 2] == '>' || s[k + 2] == '<' || s[k
			+ 2] == '|'))
		return (1);
	else if (s[k + 1] == '>')
		return (1);
	else if (s[k + 1] == '|' || s[k + 1] == ' ' || s[k + 1] == '\0')
		return (1);
	else
		return (0);
	return (1);
}

int	check_pipe(char *s, int k)
{
	if (s[k + 1] == '|' && (s[k + 2] != '>' || s[k + 2] != '<' || s[k
			+ 2] != '|'))
		return (1);
	else
		return (0);
	return (1);
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
