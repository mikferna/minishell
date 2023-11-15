/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:37:49 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/15 11:35:19 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <unistd.h>
# include <stdlib.h>
# include "minishell.h"

/*-execution.c-*/
void	execution(char **input, t_env **env);
void	redir_out(char **input, t_env **env, int i);

#endif
