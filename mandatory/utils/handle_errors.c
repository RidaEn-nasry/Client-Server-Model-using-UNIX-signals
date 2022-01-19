/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ren-nasr <ren-nasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:11:41 by ren-nasr          #+#    #+#             */
/*   Updated: 2022/01/18 16:18:59 by ren-nasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"
#include <stdlib.h>
#include <unistd.h>

void	handle_errors(int flag)
{
	if (flag == ARGC_ERR)
	{
		write(2, "WTF... I'm not executing that.\n", 31);
		exit(EXIT_FAILURE);
	}
	else if (flag == MALOC_ERR)
	{
		write(2, "Couldn't malloc... give some space greedy\n", 42);
		exit(EXIT_FAILURE);
	}
	else if (flag == KILL_ERR)
	{
		write(2, "Package didn't arrive you're obligated for a refund\n", 51);
		exit(EXIT_FAILURE);
	}
}
