/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumoncad <jumoncad@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 13:42:05 by jumoncad          #+#    #+#             */
/*   Updated: 2023/11/22 13:26:44 by jumoncad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int	x;

	x = 0;
	while (src[x])
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = '\0';
	return (dst);
}
