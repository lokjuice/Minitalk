/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wroyal <wroyal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:37:56 by wroyal            #+#    #+#             */
/*   Updated: 2021/09/11 16:54:34 by wroyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static t_talk	g_talk;

void	get_chr(int bit)
{
	g_talk.ch = g_talk.ch + ((bit & 1) << g_talk.size);
	g_talk.size++;
	if (g_talk.size == 8)
	{
		ft_putchar_fd(g_talk.ch, 1);
		if (!g_talk.ch)
			ft_putchar_fd('\n', 1);
		g_talk.size = 0;
		g_talk.ch = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	g_talk.size = 0;
	g_talk.ch = 0;
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (23)
	{
		signal(SIGUSR2, get_chr);
		signal(SIGUSR1, get_chr);
		pause();
	}
	return (0);
}
