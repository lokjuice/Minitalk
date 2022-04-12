/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wroyal <wroyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:38:00 by wroyal            #+#    #+#             */
/*   Updated: 2021/09/11 16:49:18 by wroyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	convert(int pid, char *str)
{
	int		len;
	int		i;
	int		move;

	i = 0;
	move = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		move = 0;
		while (move <= 7)
		{
			if ((str[i] >> move) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			move++;
			usleep(30);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		convert(pid, argv[2]);
	}
	else
		ft_putstr_fd("Check arguments, example: // ./client [pid] [str]\n", 1);
	return (0);
}
