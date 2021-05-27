/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:10:23 by seungnle          #+#    #+#             */
/*   Updated: 2021/05/26 07:04:14 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		my_len(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

void	my_cpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
}

char	*my_join(char *s1, char *s2)
{
	char	*ret;
	int		a;
	int		b;

	if (!s1)
		return (my_dup(s2));
	a = my_len(s1);
	b = my_len(s2);
	if (!(ret = (char *)malloc(sizeof(char) * (a + b + 1))))
		return (0);
	my_cpy(ret, s1);
	free(s1);
	my_cpy(ret + a, s2);
	return (ret);
}

char	*my_dup(char *s1)
{
	char	*ret;
	int		len;
	int		i;

	len = my_len(s1);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		++i;
	}
	ret[i] = 0;
	return (ret);
}
