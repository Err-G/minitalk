/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:26:11 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/04/18 20:34:46 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

/* lib */
void	ft_putnbr(int num);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
char	*ft_strjoinc(char *str, char c);

#endif
