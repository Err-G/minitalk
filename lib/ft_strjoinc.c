/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:13:28 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/04/18 20:34:33 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strjoinc(char *str, char c)
{
	char	*res;
	int		i;

	if (!str)
	{
		str = (char *)malloc(1);
		*str = 0;
	}
	res = (char *)malloc(ft_strlen(str) + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i++] = c;
	res[i] = 0;
	return (free(str), res);
}
