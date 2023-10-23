/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:10:24 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/23 14:00:42 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**expander(t_env *env, char **str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (str[i])
	{
		j = 0;
		while (str[i][j] && (str[i][j] != '\'' && str[i][j] != '\"'))
			j++;
		if (str[i][j] != '\'' && dollar_sign(str[i]) != 0
			&& str[i][dollar_sign(str[i])] != '\0')
		{
			tmp = ret_doll_str(env, str[i]); //aqui tiene que devolver la frase con el dolar cambiado o sin canbiar
			str[i] = tmp;
		}
		if (ft_strncmp(str[0], "export", ft_strlen(str[0]) - 1) != 0)
		{
			if (str[i][j] != '\'')
				str[i] = delete_quotes(str[i], '\"');
			else if (str[i][j] != '\"')
				str[i] = delete_quotes(str[i], '\'');
		}
		i++;
	}
	return (str);
}

char	*ret_doll_str(t_env *env, char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	while (str[i])
	{
		if (str[i] == '$')
		{
			tmp = ft_substr(str, 0, i);
			tmp = ft_strjoin(tmp, ret_dollar(env, str, i));
			while (str[i] != ' ' && str[i] != '\0')
				i++;
			tmp = ft_strjoin(tmp, &str[i]);
			//free(str);
			str = tmp;
			i = 0;
		}
		i++;
	}
	return (tmp);
}

char *ret_dollar(t_env *env, char *str, int i)
{
	t_env 	*tmp;
	char 	**str2;
	char 	*ret;

	tmp = env;
	i++;
	str2 = ft_split(&str[i], ' ');
	ret = NULL;
	printf("str2[0]-> [%s]\n", str2[0]);
	while (tmp)
	{
		if (ft_strcmp(tmp->env_name, str2[0]) == 0)
		{
			ret = malloc(sizeof(char) * ft_strlen(tmp->env));
			ret = ft_strdup(tmp->env);
			break ;
		}
		tmp = tmp->next;
	}
	return (ret);
}
