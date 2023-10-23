/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:22:31 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/23 12:21:14 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPORT_H
# define EXPORT_H

# include <unistd.h>
# include <stdlib.h>
# include "minishell.h"

/*-expander.c-*/
char	**expander(t_env *env, char **str);

/*-exp_utils.c-*/
char	*delete_quotes(char *str, char c);
size_t	dollar_sign(char *str);
char	*ret_doll_str(t_env *env, char *str);
char	*ret_dollar(t_env *env, char *str, int i);

#endif
