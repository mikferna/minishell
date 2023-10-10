/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:44:19 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/04 11:26:31 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "builtins.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <curses.h>
# include <term.h>
# include <errno.h>
# include <dirent.h>
# include <sys/types.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>

typedef struct s_ldata
{
	char *inp_line;
}		t_ldata;

/*-00_main.c-*/
int		main(int argc, char **argv, char **envp);
void	init_structs(t_ldata **line, t_env **env, char **envp);

/*-01_checker.c-*/
int		check_line_quote(char *s);
int		check_redirections(char *s);
int		check_sides(char *s, char w, int i);

/*-02_node_utils.c-*/
void	env_addback(t_env	*list, char *str, char *str2);
t_env	*ft_lstnew(char *str, char *str2);
int		ft_lstsize(t_env *lst);
char	*start_strchar(char *str, char c);
char	*end_strchar(char *str, char c);

/*-03_minishell.c-*/
void	minishell(t_ldata *line, t_env *env);

#endif