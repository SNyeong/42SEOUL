/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 21:29:42 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/16 20:16:59 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char a)
{
	if ((a >= 9 && a <= 13) || a == 32)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (!is_space(str[i]))
		++i;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result > 2147483647 && sign == 1)
			return (-1);
		if (result > 21474836478 && sign == -1)
			return (0);
		++i;
	}
	return ((int)(result * sign));
}
