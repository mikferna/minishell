/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 12:02:12 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/23 13:28:29 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_line_quote(t_ldata *s)
{
	int	comillasd;
	int	comillas;
	int	i;

	i = 0;
	comillas = 0;
	comillasd = 0;
	if (ft_check_quotes(s->inp_line, comillasd, comillas, i) == 1)
		return (1);
	if (ft_strlen(s->inp_line) == 0)
		return (2);
	if (check_redirections(s->inp_line) == 1)
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

int	ft_check_quotes(char *s, int comillasd, int comillas, int i)
{
	while (s[i])
	{
		if (s[i] == '\"' && ++comillasd)
		{
			i++;
			while (s[i] != '\"' && s[i] != '\0')
				i++;
			if (s[i] == '\"')
				comillasd++;
		}
		if (s[i] == '\'')
		{
			i++;
			comillas++;
			while (s[i] != '\'' && s[i] != '\0')
				i++;
			if (s[i] == '\'')
				comillas++;
		}
		if (s[i] != '\0')
			i++;
	}
	if (comillasd % 2 != 0 || comillas % 2 != 0)
		return (1);
	return (0);
}
