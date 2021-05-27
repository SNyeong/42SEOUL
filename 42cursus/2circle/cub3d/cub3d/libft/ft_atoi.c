/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 21:29:42 by seungnle          #+#    #+#             */
/*   Updated: 2021/05/26 15:50:57 by seungnle         ###   ########.fr       */
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
		if (result > __LONG_MAX__ && sign == 1)
			return (-1);
		if (result > __LONG_MAX__ && sign == -1)
			return (0);
		++i;
	}
	return ((int)(result * sign));
}
