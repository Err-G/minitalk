/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:13:28 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/22 20:28:00 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strjoin(char *s1, unsigned char s2)
{
	char	*str;
	int		i;

	if (!s1)
		s1 = (char *)ft_calloc(1, sizeof(char));
	if (!s1)
		return (NULL);
	str = ft_calloc(ft_strlen(s1) + 2, sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	str[i++] = s2;
	str[i] = '\0';
	free(s1);
	return (str);
}
