/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:15:03 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/24 13:00:23 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*delete_quotes(char *str, char c)
{
	int		i;
	int		j;
	char	*tmp;
	char	**split;

	i = 1;
	j = 0;
	tmp = NULL;
	split = ft_split(str, c);
	tmp = ft_substr(split[0], 0, ft_strlen(split[0]));
	while(split[i])
	{
		tmp = ft_strjoin(tmp, split[i]);
		i++;
	}
	return (tmp);
}

size_t	dollar_sign(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
			return (i + 1);
		i++;
	}
	return (0);
}
