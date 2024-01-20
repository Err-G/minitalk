/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:26:50 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/20 20:41:26 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_char(unsigned char byte)
{
	static char	*str;

}

static void	sigusr_handler(int signal)
{
	static unsigned char	byte;
	static unsigned char	byte_pos;

	if (signal == SIGUSR1)
		byte |= 1 << byte_pos;
	byte_pos++;
	if (byte_pos == 8)
		send_char(byte);
	if (signal == SIGINT)
		exit(0);
}

int main(void)
{
	int	pid;

	pid = getpid();
	signal(SIGUSR1, sigusr_handler);
	signal(SIGUSR2, sigusr_handler);
	signal(SIGINT, sigusr_handler);
	ft_putnbr(pid);
	write(1, "\n", 1);
	while (1);
	return (0);
}
