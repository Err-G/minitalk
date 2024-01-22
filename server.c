/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:26:50 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/22 20:33:08 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	save_char(unsigned char byte)
{
	static char	*str;

	str = ft_strjoin(str, byte);
	if (byte == 0)
	{
		ft_putstr(str);
		if (str)
		{
			free(str);
			str = NULL;
		}
	}
}

static void	sigusr_handler(int signal)
{
	static unsigned char	byte;
	static unsigned char	byte_pos;

	if (signal == SIGUSR1)
		byte |= 1 << byte_pos;
	byte_pos++;
	if (byte_pos == 8)
	{
		save_char(byte);
		byte = 0;
		byte_pos = 0;
	}
	if (signal == SIGINT)
	{
		save_char(0);
		exit(0);
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	signal(SIGUSR1, sigusr_handler);
	signal(SIGUSR2, sigusr_handler);
	signal(SIGINT, sigusr_handler);
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1)
		;
	return (0);
}
