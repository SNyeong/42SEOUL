/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 03:02:46 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/08 03:02:48 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*a;
	unsigned const char	*b;
	int					i;
	unsigned char		chr;

	chr = (unsigned char)c;
	i = 0;
	if (!dst && !src)
		return (0);
	a = dst;
	b = src;
	while (i < (int)n)
	{
		a[i] = b[i];
		if (b[i] == chr)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
