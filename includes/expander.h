/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:22:31 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/30 12:25:12 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPANDER_H
# define EXPANDER_H

# include <unistd.h>
# include <stdlib.h>
# include "minishell.h"

/*-expander.c-*/
char	**expander(t_env *env, char **s, int i);

/*-exp_utils.c-*/
char	*delete_quotes(char *str, char c, char *tmp, char *tmp2);
size_t	dllar_sign(char *str);
char	*ret_doll_str(t_env *env, char *str, int i, char *tmp);
char	**splitted(char *str, char **str2, char **str3, int i);
char	*ret_dollar(t_env *env, char *str, int i, char *ret);

/*-exp_utils2.c-*/
char	*process_dollar_sign(t_env *env, char **s, int i);
char	*process_quotes(char **s, int i);
char	*retu(t_env *tmp, char *ret, char **str3, char *tmp3);

#endif
