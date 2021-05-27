/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 07:12:42 by seungnle          #+#    #+#             */
/*   Updated: 2021/05/26 09:34:39 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

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

int		ft_mapcheck(t_all *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < s->map.y)
	{
		j = 0;
		while (j < s->map.x)
		{
			if (s->map.tab[i][j] != '1' && i == 0)
				return (-1);
			else if (s->map.tab[i][j] != '1' && i == s->map.y - 1)
				return (-1);
			else if (s->map.tab[i][j] != '1' && j == 0)
				return (-1);
			else if (s->map.tab[i][j] != '1' && j == s->map.x - 1)
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_parcheck(t_all *s)
{
	if (s->win.x <= 0 || s->win.y <= 0)
		return (ft_strerror(-14));
	else if ((s->tex.n == NULL || s->tex.s == NULL || s->tex.e == NULL)
			|| (s->tex.w == NULL || s->tex.i == NULL))
		return (ft_strerror(-15));
	else if (s->tex.c == NONE || s->tex.f == NONE)
		return (ft_strerror(-16));
	else if (s->err.p == 0)
		return (ft_strerror(-17));
	else if (s->err.p > 1)
		return (ft_strerror(-18));
	else if (ft_mapcheck(s) == -1)
		return (ft_strerror(-19));
	return (1);
}
