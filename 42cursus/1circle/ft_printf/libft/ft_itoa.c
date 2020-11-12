/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 05:15:19 by seungnle          #+#    #+#             */
/*   Updated: 2020/11/09 16:00:26 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_cal(char *str, int idx, int nb)
{
	if (nb == 0)
		return ;
	ft_cal(str, idx - 1, nb / 10);
	str[idx] = '0' + (nb % 10);
}

static	int		get_size(int n)
{
	int i;

	i = 0;
	while (0 != n)
	{
		n = n / 10;
		++i;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*ret;
	int		i;

	i = (n <= 0) ? 1 : 0;
	i += get_size(n);
	if (!(ret = (char *)ft_calloc(sizeof(char), (i + 1))))
		return (0);
	if (n < 0)
	{
		ret[0] = '-';
		ft_cal(ret, i - 2, -(n / 10));
		ret[i - 1] = '0' - (n % 10);
	}
	else
	{
		ft_cal(ret, i - 2, n / 10);
		ret[i - 1] = '0' + (n % 10);
	}
	ret[i] = '\0';
	return (ret);
}
