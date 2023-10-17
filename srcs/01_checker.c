/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:02:12 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/12 13:59:49 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_line_quote(char *s)
{
	int i;
	int quoted;
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
	int i;

	i = 0;
	while (s[i])
	{
		//checker_sides esta mal
		if ((s[i] == '<' || s[i] == '>' || s[i] == '|') && (check_sides(s, s[i], 0) == 1))
			return (1);
		i++;
	}
	
	return (0);
}

int	check_sides(char *s, char w, int i)
{
	int chr;
	int	chart;

	chr = 0;
	chart = 0;
	while (s[i] && (w == '<' || w == '>'))
	{
		if (s[i] != ' ' && s[i] != w)
			return (0);
		if (s[i] == '>' && s[i + 1] == '<')
			return (1);
		if (s[i] == w)
			chart++;
		i++;
	}
	while (s[i] && w == '|')
	{
		if (s[i] != w && s[i] != ' ')
			chr = 1;
		if (s[i] == '|' && chr == 0)
			return (1);
		else if (s[i] == '|' && chr == 1)
			chr = 0;
		i++;
	}
	if ((chr == 0 && s[i] == '\0') || chart > 2)
		return (1);
	return (0);
}
