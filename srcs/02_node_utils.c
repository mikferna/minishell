/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_node_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 15:15:54 by mikferna          #+#    #+#             */
/*   Updated: 2023/10/09 13:44:48 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	env_addback(t_env	*list, char *str, char *str2)
{
	t_env	*c;

	while (list->next != NULL)
		list = list->next;
	c = malloc(sizeof(t_env));
	c->env = str;
	c->env_name = str2;
	c->next = NULL;
	list->next = c;
}

t_env	*ft_lstnew(char *str, char *str2)
{
	t_env	*new;

	new = (t_env *)malloc(sizeof(t_env));
	if (new == NULL)
		return (NULL);
	new->env = str;
	new->env_name = str2;
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

char *start_strchar(char *str, char c)
{
	int		len;
	int		i;
	int		start;
	char	*ret;

	i = 0;
	start = 0;
	if (!str)
		return NULL;
	len = ft_strlen(str);
	while (str[i] && str[i] != c)
		i++;
	ret = (char *)malloc(sizeof(char) * (len - i));
	i++;
	if (!ret)
		return NULL;
	while (str[i])
		ret[start++] = str[i++];
	ret[start] = '\0';
	return (ret);
}

char *end_strchar(char *str, char c)
{
	int		i;
	int		start;
	char	*ret;

	if (!str)
		return NULL;
	int length = 0;
	while (str[length] != '\0')
		length++;
	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (!ret)
		return NULL;
	start = 0;
	while (start < i)
	{
		ret[start] = str[start];
		start++;
	}
	ret[start] = '\0';
	return (ret);
}
