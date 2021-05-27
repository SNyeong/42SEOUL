/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 02:22:51 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/16 21:42:28 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	size_t			i;

	ch = (unsigned char)c;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == ch)
			return ((char *)s + i);
		--i;
	}
	if (s[i] == ch)
		return ((char *)s);
	return (0);
}
