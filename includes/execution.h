/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:37:49 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/18 12:03:43 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <unistd.h>
# include <stdlib.h>
# include "minishell.h"

/*-execution.c-*/
void	execution(char **input, t_env **env);
int		redir_out(char **input, t_env **env, int i);
int		redir_in(char **input, t_env **env, int i);
int		redir_append(char **input, t_env **env, int i);
int		redir_here_document(char **input, t_env **env, int i);

#endif
