/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:26:11 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/04/18 18:03:59 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

/* lib */
void	ft_putstr(char *str);
void	ft_putnbr(int num);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strlen(char *str);
int		ft_atoi(char *str);
char	*ft_strjoin(char *s1, unsigned char s2);

#endif
