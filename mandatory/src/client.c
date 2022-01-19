/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:38:59 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/01/19 23:23:42 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "../include/minitalk.h"
#include <stdlib.h>

void	sender(char c, pid_t pid)
{
	int	i;
	int	kill_check;

	i = 0x80;
	while (i)
	{
		if (c & i)
			kill_check = kill(pid, SIGUSR1);
		else
			kill_check = kill(pid, SIGUSR2);
		if (kill_check == -1)
			handle_errors(KILL_ERR);
		i >>= 1;
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	i = 0;
	if (argc != 3)
		handle_errors(ARGC_ERR);
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		sender(argv[2][i], pid);
		i++;
	}
	return (0);
}
