/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 04:11:56 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/08 04:11:58 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	b;
	size_t			i;

	i = 0;
	a = (unsigned char *)s;
	b = (unsigned char)c;
	while (n--)
	{
		if (a[i] == b)
			return (a + i);
		++i;
	}
	return (0);
}
