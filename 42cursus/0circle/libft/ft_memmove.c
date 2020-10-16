/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 03:57:30 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/16 21:17:36 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*a;
	unsigned const char	*b;

	if (!dst && !src)
		return (0);
	a = dst;
	b = src;
	if (b < a)
	{
		while (len--)
		{
			a[len] = b[len];
		}
	}
	else
	{
		while (len--)
			*a++ = *b++;
	}
	return (dst);
}
