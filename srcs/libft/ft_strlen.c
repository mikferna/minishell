/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 16:01:16 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/03 11:28:08 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

size_t	ft_strlen(const char *str)
{
	int	c;

	c = 0;
	if (!str)
		return (0);
	while (*str != '\0')
	{
		c++;
		str++;
	}
	return (c);
}
