/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_node_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:15:54 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/23 13:08:17 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	env_addback(t_env	*list, char *str, char *str2, t_ldata *line)
{
	t_env	*c;

	while (list->next != NULL)
		list = list->next;
	c = malloc(sizeof(t_env));
	c->env = str;
	c->env_name = str2;
	c->data = line;
	c->next = NULL;
	list->next = c;
}

t_env	*ft_lstnew(char *str, char *str2, t_ldata *line)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (new == NULL)
		return (NULL);
	new->env = str;
	new->env_name = str2;
	new->data = line;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_env *lst)
{
	t_env	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_lstadd_back(t_env *lst, t_env *new)
{
	while (lst->next)
	{
		lst = lst->next;
	}
	lst->next = new;
}
