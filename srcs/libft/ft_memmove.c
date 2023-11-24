/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:03:20 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/23 15:38:13 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src == 0 && dst == 0)
		return (0);
	if (dst < src)
	{
		while (n)
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
			n--;
		}
	}
	else
	{
		while (n)
		{
			((char *)dst)[n - 1] = ((char *)src)[n - 1];
			n--;
		}
	}
	return (dst);
}
