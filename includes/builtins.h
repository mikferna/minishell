/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:12:33 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/10 14:11:34 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include <unistd.h>
# include <stdlib.h>
# include "minishell.h"

//puede que lo de abajo de error no lo he probado
typedef struct s_env t_env;
typedef struct s_ldata t_ldata;

/*-cd.c-*/
int		cd(t_env *env, char **args);
int		home_cd(t_env *env);
void	update_pwd(char *pwd, t_env *env, char *path);
int		go_back(t_env *env);
int		s_case(t_env *env);

/*-cd1.c-*/
int		absolute_path(t_env *env, char *path);
int		do_nothing(void);

/*-pwd.c-*/
int		pwd(char **args);

/*-export.c-*/
int		export(t_env *env, char **args);
int		do_export(t_env *env, t_env	*temp, char **args);

/*-unset.c-*/
int		unset(t_env **env, char **args);
void	do_unset(t_env **env, t_env *temp, t_env *temp2, int x);

/*-env.c-*/
int		envi(t_env *env, char **args);

/*-exit.c-*/
int		exitt(char **args);

/*-env_gen.c-*/
void	get_env(char **envp, t_env **env, t_ldata **line);

/*-echo.c-*/
int		mini_echo(t_env *env, char **args);

/*-utils.c-*/
char	*get_path(t_env *env, char *dir);
int		ft_strcmp(char *s1, char *s2);


#endif
