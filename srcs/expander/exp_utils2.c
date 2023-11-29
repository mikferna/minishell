/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exp_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:30:05 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/29 13:30:14 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*retu(t_env *tmp, char *ret, char **str3, char *tmp3)
{
	if (str3[0][0] == '?')
		return (ft_strjoin2(ft_itoa(g_error_num), tmp3, 0));
	while (tmp)
	{
		if (ft_strcmp(tmp->env_name, str3[0]) == 0)
		{
			ret = ft_strdup(tmp->env);
			break ;
		}
		tmp = tmp->next;
	}
	return (ret);
}
