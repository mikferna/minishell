/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:44:19 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/17 12:42:21 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "builtins.h"
# include "libft.h"
# include <curses.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <term.h>
# include <unistd.h>

typedef struct s_ldata
{
	char	*inp_line;
}			t_ldata;

/*-00_main.c-*/
int			main(int argc, char **argv, char **envp);
void		init_structs(t_ldata **line, t_env **env, char **envp);

/*-01_checker.c-*/
int			check_line_quote(char *s);
int			check_redirections(char *s);
// int		check_sides(char *s, char w, int i);
int			ft_check_redir(char *s);
int			check_stdin(char *s, int k);
int			check_stdout(char *s, int k);
int			check_pipe(char *s, int k);
int			check_redirection(char *s, int i);

/*-02_node_utils.c-*/
void		env_addback(t_env *list, char *str, char *str2);
t_env		*ft_lstnew(char *str, char *str2);
int			ft_lstsize(t_env *lst);
char		*start_strchar(char *str, char c);
char		*end_strchar(char *str, char c);

/*-03_minishell.c-*/
void		minishell(t_ldata *line, t_env *env);

#endif