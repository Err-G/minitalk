/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:33:44 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/04/18 20:37:45 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send(int pid, unsigned char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(50);
	}
}

static void	send_string(int pid, char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		send(pid, (unsigned char)str[i]);
	send(pid, 0);
}

static int	usage(char *name)
{
	write(1, "usage: ", 7);
	write(1, name, ft_strlen(name));
	write(1, " [pid] [text-to-send]\n", 22);
	return (1);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		return (usage(av[0]));
	pid = ft_atoi(av[1]);
	send_string(pid, av[2]);
	return (0);
}
