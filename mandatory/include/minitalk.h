/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:46:29 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/01/18 16:37:49 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>

// Errors Macors
# define ARGC_ERR 0
# define MALOC_ERR 1
# define KILL_ERR 2

// ==> error handling
void	handle_errors(int err);

// ===> utils function
void	ft_putstr_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);

// ===> Encoder & Decoder
int		*encoder(char c);
char	decoder(int *sequence);

#endif
