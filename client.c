/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:33:44 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/22 20:33:29 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(int pid, unsigned char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if ((c >> i & 1) != 0)
		{
			kill(pid, SIGUSR1);
			write(1, "1", 1);
		}
		else
		{
			kill(pid, SIGUSR2);
			write(1, "0", 1);
		}
		usleep(150);
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac < 2)
		return (1);
	pid = ft_atoi(av[1]);
	send(pid, 'i');
	send(pid, '\0');
	return (0);
}
