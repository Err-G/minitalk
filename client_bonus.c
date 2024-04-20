/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:33:44 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/04/20 18:47:49 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

static void	send(int pid, unsigned char c)
{
	int	i;
	int	sig;

	i = -1;
	while (++i < 8)
	{
		if ((c >> i) & 1)
			sig = SIGUSR1;
		else
			sig = SIGUSR2;
		kill(pid, sig);
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

static void	sig_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		write(1, "Message sent!\n", 14);
		exit(0);
	}
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		return (usage(av[0]));
	pid = ft_atoi(av[1]);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	send_string(pid, av[2]);
	pause();
	return (0);
}
