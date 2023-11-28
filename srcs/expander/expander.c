/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:10:24 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/28 14:31:09 by mikferna         ###   ########.fr       */
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
			s[i] = ft_strdup(tmp);
			if (tmp)
				free(tmp);
		}
		init_j(&j, s[i]);
		if (ft_strncmp(s[0], "export", ft_strlen(s[0]) - 1) != 0)
		{
			if (s[i][j] == '\'')
				s[i] = ft_strdup(delete_quotes(s[i], '\''));
			else if (s[i][j] == '\"')
				s[i] = ft_strdup(delete_quotes(s[i], '\"'));
		}
		i++;
	}
	return (s);
}

char	*ret_doll_str(t_env *env, char *str, int i, char *tmp)
{
	char	*ret_dll;
	char	*ret;

	while (str[i])
	{
		if (str[i] == '$')
		{
			i++;
			ret_dll = ret_dollar(env, str, i - 1, NULL);
			tmp = ft_substr(str, 0, i - 1);
			if (str[i] != '\'')
			{
				ret = ft_strjoin(tmp, ret_dll);
				if (ft_strlen(tmp) > 0)
					free(tmp);
			}
			while (str[i] == '\"')
				i++;
			while (str[i] != ' ' && str[i] != '\0' && str[i] != '\"'
				&& str[i] != '\'' && str[i] != '$')
				i++;
			tmp = ft_strjoin(ret, &str[i]);
			free(ret);
			if (ft_strcmp(tmp, "") == 0)
				tmp = ft_strdup(" ");
			i = -1;
			str = tmp;
			if (ft_strlen(ret_dll) >= 0)
				free(ret_dll);
		}
		i++;
	}
	if (!tmp)
		tmp = ft_strdup(" ");
	return (tmp);
}

char	**splitted(char *str, char **str2, char **str3, int i)
{
	char	**str4;
	char	**str5;

	str2 = ft_split(&str[i], ' ');
	if (!str2[0])
	{
		free_split(str2);
		return (NULL);
	}
	str3 = ft_split(str2[0], '\"');
	free_split(str2);
	str4 = ft_split(str3[0], '\'');
	free_split(str3);
	str5 = ft_split(str4[0], '$');
	free_split(str4);
	return (str5);
}

char	*ret_dollar(t_env *env, char *str, int i, char *ret)
{
	t_env	*tmp;
	char	**str3;
	char	*tmp3;

	tmp = env;
	i++;
	str3 = splitted(str, NULL, NULL, i);
	tmp3 = ft_strtrim(str3[0], "?");
	i = 1;
	if (!str3[0])
	{
		free(tmp3);
		return (ft_strdup(""));
	}
	if (str3[0][0] == '?')
	{
		free_split(str3);
		return (ft_strjoin2(ft_itoa(g_error_num), tmp3, 0));
	}
	while (tmp)
	{
		if (ft_strcmp(tmp->env_name, str3[0]) == 0)
		{
			ret = ft_strdup(tmp->env);
			break ;
		}
		tmp = tmp->next;
	}
	free(tmp3);
	free_split(str3);
	if (!ret)
		return (ft_strdup(""));
	return (ret);
}
