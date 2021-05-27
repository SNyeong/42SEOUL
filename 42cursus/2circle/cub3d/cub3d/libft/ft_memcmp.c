/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 22:51:25 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/08 22:51:26 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;
	int				i;

	if (!s1 && !s2)
		return (0);
	i = 0;
	a = (unsigned char *)s1;
	b = (unsigned char *)s2;
	while (n--)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		++i;
	}
	return (0);
}
