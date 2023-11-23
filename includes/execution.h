/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:37:49 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/23 13:06:34 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_H
# define EXECUTION_H

# include <unistd.h>
# include <stdlib.h>
# include "minishell.h"

/*-execution.c-*/
char	*str_ndup(char *str, unsigned int n);
int		str_ichr(char *str, char c);
char	*get_path_env(t_env *env);
char	*path_join(char *path, char *bin);
char	*exec_bin(char **input, t_env **env);

/*-execution2.c-*/
void	exec_cmd(char **input, t_env **env);
char	**obtener_input(char **input, char *c);
int		redir_out(char **input, t_env **env, int i);
int		redir_in(char **input, t_env **env, int i);
char	**change_heredoc(char	**original);

/*-execution3.c-*/
int		redir_here_document(char **input, t_env **env, int i);
int		redir_append(char **input, t_env **env, int i);
void	execution(char **input, t_env **env);

#endif
