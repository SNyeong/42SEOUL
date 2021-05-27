/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 07:30:26 by seungnle          #+#    #+#             */
/*   Updated: 2021/05/06 22:14:47 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_option(t_option *option)
{
	option->minus = 0;
	option->zero = 0;
	option->width = 0;
	option->precision = -1;
	option->type = 0;
	option->sign = 1;
	option->base = 10;
}

void	check_option(t_option *option)
{
	if (option->type == '%' && option->zero)
		option->zero = (option->minus) ? 0 : 1;
	else if (option->minus || option->precision >= 0)
		option->zero = 0;
}

char	*ft_base(char c)
{
	if (c == 'd' || c == 'i' || c == 'u')
		return ("0123456789");
	else if (c == 'x' || c == 'p')
		return ("0123456789abcdef");
	else if (c == 'X')
		return ("0123456789ABCDEF");
	return (0);
}

int		ft_nblen(unsigned long long nb, t_option *option)
{
	int i;

	if (nb == 0 && option->precision)
		return (1);
	i = 0;
	while (nb)
	{
		i++;
		nb /= option->base;
	}
	return (i);
}

void	ft_swap(char *c1, char *c2)
{
	char	c;

	c = *c1;
	*c1 = *c2;
	*c2 = c;
}
