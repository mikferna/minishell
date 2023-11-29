/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikferna <mikferna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:06:24 by mikferna          #+#    #+#             */
/*   Updated: 2023/11/29 12:26:27 by mikferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../../includes/minishell.h"

static int	count(int a)
{
	int	i;

	i = 1;
	while (a / 10 != 0)
	{
		i++;
		a = a / 10;
	}
	if (a < 0)
		i = i + 1;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*strnum;
	int		counter;
	int		str_length;
	long	nb;

	nb = n;
	str_length = count(nb);
	strnum = (char *)malloc(sizeof(char) * (str_length + 1));
	if (!(strnum))
		return (NULL);
	strnum[str_length] = '\0';
	counter = 0;
	if (nb < 0)
	{
		strnum[counter] = '-';
		nb = nb * -1;
	}
	if (nb == 0)
		strnum[0] = '0';
	while (nb > 0)
	{
		strnum[str_length - counter++ - 1] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (strnum);
}
