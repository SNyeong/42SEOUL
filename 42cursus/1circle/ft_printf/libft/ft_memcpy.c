/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 21:15:32 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/08 01:44:09 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*a;
	unsigned const char	*b;

	if (!dst && !src)
		return (0);
	a = dst;
	b = src;
	while (n--)
		*a++ = *b++;
	return (dst);
}
