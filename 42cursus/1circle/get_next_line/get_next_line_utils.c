/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 10:06:42 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/23 11:10:18 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	len;
	size_t	i;

	if (!dst && !src)
		return (0);
	len = 0;
	while (src[len])
		++len;
	if (dstsize == 0)
		return (len);
	i = 0;
	while (src[i] != 0 && i < (dstsize - 1))
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	a;
	size_t	b;

	if (!s1 && !s2)
		return (0);
	else if (!s1 || !s2)
		return (!s1 ? ft_strdup(s2) : ft_strdup(s1));
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(char) * (a + b + 1))))
		return (0);
	ft_strlcpy(ret, s1, a + 1);
	free(s1);
	ft_strlcpy(ret + a, s2, b + 1);
	return (ret);
}

char	*ft_strdup(char *s1)
{
	char	*ret;
	size_t	len;
	int		i;

	len = ft_strlen(s1);
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
