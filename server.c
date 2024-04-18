/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:26:50 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/04/18 17:59:20 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_handler(int signal)
{
	static unsigned char	byte;
	static unsigned char	byte_pos;
	static char				*str;

	if (signal == SIGUSR1)
		byte |= 1 << byte_pos;
	byte_pos++;
	if (byte_pos == 8)
	{
		str = ft_strjoin(str, byte);
		if (byte == 0)
		{
			ft_putstr(str);
			free(str);
			str = NULL;
		}
		byte = 0;
		byte_pos = 0;
	}
	if (signal == SIGINT)
	{
		free(str);
		exit(0);
	}
}

int	main(void)
{
	int					pid;

	pid = getpid();
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	signal(SIGINT, sig_handler);
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		;
	return (0);
}
