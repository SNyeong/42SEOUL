/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 06:13:51 by seungnle          #+#    #+#             */
/*   Updated: 2021/05/28 06:47:02 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int		ft_check_file(char *arg, char *str)
{
	int i;

	i = 0;
	while (arg[i])
		++i;
	if (i > 4 && arg[i - 1] == str[2] && arg[i - 2] == str[1] &&
		arg[i - 3] == str[0] && arg[i - 4] == '.')
		return (1);
	return (0);
}

int		ft_check_save(char *arg, char *str)
{
	int	i;

	i = 0;
	while (arg[i] == str[i])
	{
		if (arg[i] == '\0' && str[i] == '\0')
			return (1);
		i++;
	}
	return (0);
}

float	degree(float radian)
{
	return (radian * 180 / PI);
}

float	radian(float degree)
{
	return (degree * PI / 180);
}
