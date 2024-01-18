/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:26:50 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/01/18 20:29:45 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_putnbr(int num)
{
	unsigned int	n;

	n = num;
	if (num < 0)
	{
		n = -num;
		write(1, "-", 1);
	}
	if (n >= 10)
		ft_putnbr(n % 10);
	write(1, &"0123456789"[n / 10], 1);
}

int main(int ac, char **av)
{
	int	pid;

	pid = getpid();
	ft_putnbr(pid);
	return (0);
}
