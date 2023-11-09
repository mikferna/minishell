/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:14:55 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/08 13:40:28 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTIONS_H
# define REDIRECTIONS_H

# include <unistd.h>
# include <stdlib.h>
# include "minishell.h"

typedef struct s_pipes
{
	char *before;
	char *after;
	char *redir;
	struct s_pipes	*next;
}		t_pipes;

/*-execution.c-*/
void	execution(char **input, t_env **env);

#endif
