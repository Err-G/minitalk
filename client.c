/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 17:33:44 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/23 17:53:28 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send(int pid, unsigned char c)
{
	int	i;

	i = -1;
	while (++i < 8)
	{
		if (ft_bitpos(c, i))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
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
	ft_putstr("usage: ");
	ft_putstr(name);
	ft_putstr(" [pid] [text-to-send]\n");
	return (1);
}

static void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Success!\n", 9);
	exit(0);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac < 3)
		return (usage(av[0]));
	signal(SIGUSR1, signal_handler);
	pid = ft_atoi(av[1]);
	send_string(pid, av[2]);
	pause();
	return (0);
}
