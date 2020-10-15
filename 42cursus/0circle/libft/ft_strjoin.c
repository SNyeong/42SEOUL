/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:25:13 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/16 06:22:05 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
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
	if (!(ret = (char *)ft_calloc(sizeof(char), (a + b + 1))))
		return (0);
	ft_strlcpy(ret, s1, a + 1);
	ft_strlcpy(ret + a, s2, b + 1);
	return (ret);
}
