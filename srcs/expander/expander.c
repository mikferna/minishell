/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:10:24 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/29 13:32:11 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* char	**expander(t_env *env, char **s, char *tmp, int i)
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
				s[i] = delete_quotes(s[i], '\'', NULL, NULL);
			else if (s[i][j] == '\"')
				s[i] = delete_quotes(s[i], '\"', NULL, NULL);
		}
		i++;
	}
	return (s);
} */
char	**expander(t_env *env, char **s, int i)
{
	while (s[i])
	{
		s[i] = process_dollar_sign(env, s, i);
		s[i] = process_quotes(s, i);
		i++;
	}
	return (s);
}

char	*ret_doll_str(t_env *env, char *str, int i, char *tmp)
{
	char	*ret_dll;
	char	*ret;
	char	*tmp2;

	tmp2 = ft_strdup(str);
	while (tmp2[i])
	{
		if (tmp2[i + 1] && tmp2[i] == '$')
		{
			i++;
			ret_dll = ret_dollar(env, tmp2, i - 1, NULL);
			tmp = ft_substr(tmp2, 0, i - 1);
			if (!tmp)
				tmp = ft_strdup("");
			if (tmp2[i] != '\'')
			{
				ret = ft_strjoin(tmp, ret_dll);
				free(tmp);
			}
			while (tmp2[i] == '\"')
				i++;
			while (tmp2[i] != ' ' && tmp2[i] != '\0' && tmp2[i] != '\"'
				&& tmp2[i] != '\'' && tmp2[i] != '$')
				i++;
			tmp = ft_strjoin(ret, &tmp2[i]);
			free(ret);
			if (ft_strcmp(tmp, "") == 0)
			{
				free(tmp);
				tmp = ft_strdup(" ");
			}
			i = -1;
			free(tmp2);
			tmp2 = ft_strdup(tmp);
			free(tmp);
			if (ft_strlen(ret_dll) >= 0)
				free(ret_dll);
		}
		i++;
	}
	tmp = ft_strdup(tmp2);
	free(tmp2);
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
		free_split(str3);
		return (ft_strdup(""));
	}
	ret = retu(tmp, ret, str3, tmp3);
	free(tmp3);
	free_split(str3);
	if (!ret)
		return (ft_strdup(""));
	return (ret);
}
