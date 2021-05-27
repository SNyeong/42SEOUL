/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:55:46 by seungnle          #+#    #+#             */
/*   Updated: 2020/11/09 15:57:03 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_st(char const *s1, char const *set)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		++i;
	}
	return (i);
}

int		get_end(char const *s1, char const *set)
{
	int len;

	len = ft_strlen(s1);
	while (len--)
	{
		if (ft_strchr(set, s1[len]) == 0)
			break ;
	}
	return (len + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	int		start;
	int		end;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = get_st(s1, set);
	end = get_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	if (!(ret = (char *)ft_calloc(sizeof(char), (end - start + 1))))
		return (0);
	ft_strlcpy(ret, s1 + start, end - start + 1);
	return (ret);
}
