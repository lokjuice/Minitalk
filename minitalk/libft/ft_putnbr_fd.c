/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wroyal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:27:04 by wroyal            #+#    #+#             */
/*   Updated: 2021/05/01 15:54:54 by wroyal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			a;
	unsigned int	m;

	if (n < 0)
	{
		write(fd, "-", 1);
		m = (unsigned int)(n * -1);
	}
	if (n >= 0)
		m = (unsigned int)n;
	if (m > 9)
		ft_putnbr_fd(m / 10, fd);
	a = m % 10 + '0';
	write(fd, &a, 1);
}
