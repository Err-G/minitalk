/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:26:50 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/23 17:42:38 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	save_char(unsigned char byte, siginfo_t *info)
{
	static char	*str;

	str = ft_strjoin(str, byte);
	if (byte == 0)
	{
		ft_putstr(str);
		free(str);
		str = NULL;
		kill(info->si_pid, SIGUSR1);
	}
}

static void	signal_handler(int signal, siginfo_t *info, void *ucontext)
{
	static unsigned char	byte;
	static unsigned char	byte_pos;

	(void)ucontext;
	if (signal == SIGUSR1)
		byte |= 1 << byte_pos;
	byte_pos++;
	if (byte_pos == 8)
	{
		save_char(byte, info);
		byte = 0;
		byte_pos = 0;
	}
	if (signal == SIGINT)
	{
		save_char(0, info);
		exit(0);
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	act;

	pid = getpid();
	act.sa_sigaction = &signal_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	sigaction(SIGINT, &act, NULL);
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		;
	return (0);
}
