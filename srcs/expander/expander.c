/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:10:24 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/22 10:56:22 by mikferna         ###   ########.fr       */
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
		while (str[i][j] && (str[i][j] != '\'' && str[i][j] != '\"') && str[i][j] != '$')
			j++;
		if (str[i][j] != '\'' && dollar_sign(str[i]) != 0
			&& str[i][dollar_sign(str[i])] != '\0')
		{
			tmp = ret_doll_str(env, str[i], 0);
			free(str[i]); //aqui tiene que devolver la frase con el dolar cambiado o sin cambiar
			str[i] = tmp;
		}
		j = 0;
		while (str[i][j] && (str[i][j] != '\'' && str[i][j] != '\"'))
			j++;
		if (ft_strncmp(str[0], "export", ft_strlen(str[0]) - 1) != 0)
		{
			if (str[i][j] == '\'')
				str[i] = delete_quotes(str[i], '\'');
			else if (str[i][j] == '\"')
				str[i] = delete_quotes(str[i], '\"');
		}
		i++;
	}
	return (str);
}

char	*ret_doll_str(t_env *env, char *str, int i)
{
	char	*tmp;

	tmp = NULL;
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			tmp = ft_substr(str, 0, i - 1);
			if (str[i] != '\'')
				tmp = ft_strjoin(tmp, ret_dollar(env, str, i - 1));
			while(str[i] == '\"')
				i++;
			while (str[i] != ' ' && str[i] != '\0' && str[i] != '\"' && str[i] != '\'' && str[i] != '$')
				i++;
			tmp = ft_strjoin(tmp, &str[i]);
			if (ft_strcmp(tmp, "") == 0)
				tmp = " ";
			i = -1;
			str = tmp;
		}
		i++;
	}
	if (!tmp)
		tmp = " ";
	return (tmp);
}

char *ret_dollar(t_env *env, char *str, int i)
{
	t_env 	*tmp;
	char 	**str2;
	char	**str3;
	char 	*ret;

	tmp = env;
	i++;
	str2 = ft_split(&str[i], ' ');
	if (!str2[0])
		return ("");
	str3 = ft_split(str2[0], '\"');
	str3 = ft_split(str3[0], '\'');
	str3 = ft_split(str3[0], '$');
	i = 1;
	ret = NULL;
	if (!str3[0])
		return ("");
	if (str3[0][0] == '?')
		return (ft_strjoin(ft_itoa(g_global.error_num), ft_strtrim(str3[0], "?")));
	while (tmp)
	{
		if (ft_strcmp(tmp->env_name, str3[0]) == 0)
		{
			ret = malloc(sizeof(char) * ft_strlen(tmp->env));
			ret = ft_strdup(tmp->env);
			break ;
		}
		tmp = tmp->next;
	}
	if (!ret)
		return ("");
	return (ret);
}
