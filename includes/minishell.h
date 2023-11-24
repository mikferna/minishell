/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:44:19 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/24 12:51:30 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "builtins.h"
# include "execution.h"
# include "expander.h"
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
	char			*inp_line;
	char			**envp;
	char			**input_cpy;
	char			**split_pipes;
	int				stdout_cpy;
	int				stdin_cpy;

	char			**input;
	int				pipe_fd[2];
	int				prev_pipe;

}					t_ldata;

typedef struct s_token
{
	char			*inp_line;
}					t_token;

typedef struct s_env
{
	char			*env_name;
	char			*env;
	char			*key;
	char			*value;
	struct s_ldata	*data;
	struct s_env	*next;
}					t_env;

int					g_error_num;

// readline
void				rl_replace_line(const char *text, int clear_undo);

/*-00_main.c-*/
int					main(int argc, char **argv, char **envp);
void				init_structs(t_ldata **line, t_env **env, char **envp);
void				init_minishell(t_ldata *line, t_env *env);

/*-01_checker.c-*/
int					check_line_quote(t_ldata *s);
int					check_redirections(char *s);
int					check_sides(char *s, char w, int i);
int					ft_check_quotes(char *s, int comillasd, int comillas,
						int i);

/*-02_node_utils.c-*/
void				env_addback(t_env *list, char *str, char *str2,
						t_ldata *line);
t_env				*ft_lstnew(char *str, char *str2, t_ldata *line);
int					ft_lstsize(t_env *lst);
void				ft_lstadd_back(t_env *lst, t_env *new);
char				*start_strchar(char *str, char c);
char				*end_strchar(char *str, char c);
char				**ft_splt_cmls(char const *s, char c, int comillad,
						int comillas);

/*-03_minishell.c-*/
void				minishell(t_ldata *line, t_env **env);

/*-04_check_redir.c-*/
int					ft_check_redir(char *s);
int					ft_doublesize(const char *s, char c);

/*-05_signal.c*/
void				run_singl(int num);

#endif