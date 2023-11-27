/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:10:24 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/27 12:20:12 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_j(int *j, char *s)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] != '\'' && s[i] != '\"'))
		i++;
	*j = i;
}

char	**expander(t_env *env, char **s, char *tmp, int i)
{
	int	j;

	while (s[i])
	{
		j = 0;
		while (s[i][j] && (s[i][j] != '\'' && s[i][j] != '"') && s[i][j] != '$')
			j++;
		if (s[i][j] != '\'' && dllar_sign(s[i]) != 0 && s[i][dllar_sign(s[i])])
		{
			tmp = ret_doll_str(env, s[i], 0, NULL);
			free(s[i]);
			s[i] = tmp;
		}
		init_j(&j, s[i]);
		if (ft_strncmp(s[0], "export", ft_strlen(s[0]) - 1) != 0)
		{
			if (s[i][j] == '\'')
				s[i] = delete_quotes(s[i], '\'');
			else if (s[i][j] == '\"')
				s[i] = delete_quotes(s[i], '\"');
		}
		i++;
	}
	return (s);
}

char	*ret_doll_str(t_env *env, char *str, int i, char *tmp)
{
	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			tmp = ft_substr(str, 0, i - 1);
			if (str[i] != '\'')
				tmp = ft_strjoin(tmp, ret_dollar(env, str, i - 1, NULL));
			while (str[i] == '\"')
				i++;
			while (str[i] != ' ' && str[i] != '\0' && str[i] != '\"'
				&& str[i] != '\'' && str[i] != '$')
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

char	**splitted(char *str, char **str2, char **str3, int i)
{
	str2 = ft_split(&str[i], ' ');
	if (!str2[0])
		return (NULL);
	str3 = ft_split(str2[0], '\"');
	str3 = ft_split(str3[0], '\'');
	str3 = ft_split(str3[0], '$');
	//aqui
	//free_split(str2);
	return (str3);
}

char	*ret_dollar(t_env *env, char *str, int i, char *ret)
{
	t_env	*tmp;
	char	**str3;

	tmp = env;
	i++;
	str3 = splitted(str, NULL, NULL, i);
	i = 1;
	if (!str3[0])
		return ("");
	if (str3[0][0] == '?')
		return (ft_strjoin(ft_itoa(g_error_num), ft_strtrim(str3[0], "?")));
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
	//aqui
	//free_split(str3);
	if (!ret)
		return ("");
	return (ret);
}
