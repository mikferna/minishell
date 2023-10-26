/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:44:19 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/26 12:03:07 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "builtins.h"
# include "expander.h"
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

typedef struct s_token
{
	char *inp_line;
}		t_token;

typedef struct s_env
{
	char			*env_name;
	char			*env;
	struct s_env	*next;
}				t_env;

typedef struct s_global
{
	int	error_num;
}	t_global;

t_global	g_global;

/*-00_main.c-*/
int		main(int argc, char **argv, char **envp);
void	init_structs(t_ldata **line, t_env **env, char **envp);

/*-01_checker.c-*/
int		check_line_quote(t_ldata *s);
int		check_redirections(char *s);
int		check_sides(char *s, char w, int i);
int		ft_check_quotes(char *s, int comillasd, int comillas, int i);

/*-02_node_utils.c-*/
void	env_addback(t_env	*list, char *str, char *str2);
t_env	*ft_lstnew(char *str, char *str2);
int		ft_lstsize(t_env *lst);
void	ft_lstadd_back(t_env *lst, t_env *new);
char	*start_strchar(char *str, char c);
char	*end_strchar(char *str, char c);
char	**ft_split_comillas_dobles(char const *s, char c);

/*-03_minishell.c-*/
void	minishell(t_ldata *line, t_env *env);

/*-04_check_redir.c-*/
int			ft_check_redir(char *s);

#endif