/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:26:50 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/04/20 18:04:55 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_put_str(char **str, siginfo_t *info)
{
	write(1, *str, ft_strlen(*str));
	free(*str);
	*str = NULL;
	kill(info->si_pid, SIGUSR1);
}

static void	signal_handler(int signal, siginfo_t *info, void *ucontext)
{
	static unsigned char	byte;
	static unsigned char	byte_pos;
	static char				*str;

	(void)ucontext;
	if (signal == SIGUSR1)
		byte |= 1 << byte_pos;
	if (signal == SIGUSR1 || signal == SIGUSR2)
		byte_pos++;
	if (byte_pos == 8)
	{
		str = ft_strjoinc(str, byte);
		if (byte == '\0')
			ft_put_str(&str, info);
		byte = 0;
		byte_pos = 0;
	}
	if (signal == SIGINT)
	{
		free(str);
		exit(0);
	}
	kill(info->si_pid, SIGUSR2);
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
		pause();
	return (0);
}
