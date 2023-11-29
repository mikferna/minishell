/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:15:07 by jumoncad          #+#    #+#             */
/*   Updated: 2023/11/29 13:17:23 by jumoncad         ###   ########.fr       */
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

char	*process_dollar_sign(t_env *env, char **s, int i)
{
    char	*tmp;
    int		j;

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
    return (s[i]);
}

char	*process_quotes(char **s, int i)
{
    int		j;

    init_j(&j, s[i]);
    if (ft_strncmp(s[0], "export", ft_strlen(s[0]) - 1) != 0)
    {
        if (s[i][j] == '\'')
            s[i] = delete_quotes(s[i], '\'', NULL, NULL);
        else if (s[i][j] == '\"')
            s[i] = delete_quotes(s[i], '\"', NULL, NULL);
    }
    return (s[i]);
}