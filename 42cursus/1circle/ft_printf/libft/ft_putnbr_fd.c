/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:42:46 by seungnle          #+#    #+#             */
/*   Updated: 2020/11/04 22:20:46 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_cal(int n, int fd)
{
	char ch;

	if (n == 0)
		return ;
	ft_cal(n / 10, fd);
	ch = '0' + (n % 10);
	write(fd, &ch, 1);
}

void			ft_putnbr_fd(int n, int fd)
{
	char ch;

	if (n < 0)
	{
		write(fd, "-", 1);
		ft_cal(-(n / 10), fd);
		ch = '0' - (n % 10);
	}
	else
	{
		ft_cal(n / 10, fd);
		ch = '0' + (n % 10);
	}
	write(fd, &ch, 1);
}
