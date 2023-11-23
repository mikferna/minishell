/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_node_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:07:29 by jumoncad          #+#    #+#             */
/*   Updated: 2023/11/23 13:08:27 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*end_strchar(char *str, char c)
{
	int		len;
	int		i;
	int		start;
	char	*ret;

	i = 0;
	start = 0;
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	while (str[i] && str[i] != c)
		i++;
	if (i == len)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (len - i));
	i++;
	if (!ret)
		return (NULL);
	while (str[i])
		ret[start++] = str[i++];
	ret[start] = '\0';
	return (ret);
}

char	*start_strchar(char *str, char c)
{
	int		i;
	int		start;
	char	*ret;
	int		len;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (i == len)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	start = 0;
	while (start < i)
	{
		ret[start] = str[start];
		start++;
	}
	ret[start] = '\0';
	return (ret);
}
