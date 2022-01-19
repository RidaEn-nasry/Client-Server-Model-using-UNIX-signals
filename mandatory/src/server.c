/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:32:08 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/01/19 23:39:02 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../include/minitalk.h"
#include <signal.h>
#include <limits.h>

void	handler(int signal, siginfo_t *info, void *context)
{
	static int	i;
	static char	c;
	static int	pidd;
	int			newpid;

	if (!pidd)
		pidd = info->si_pid;
	newpid = info->si_pid;
	if (pidd != newpid)
	{
		i = 0;
		c = 0;
	}
	(void)context;
	c <<= 1;
	c += signal == SIGUSR1;
	if (++i == CHAR_BIT)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	pidd = info->si_pid;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = handler;
	pid = getpid();
	ft_putstr_fd("pid: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	while (1)
	{
		sigaction(SIGUSR1, &act, NULL);
		sigaction(SIGUSR2, &act, NULL);
		pause();
	}
}
