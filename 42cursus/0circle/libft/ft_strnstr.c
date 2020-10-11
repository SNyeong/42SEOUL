/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 02:36:12 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/09 02:36:13 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *og, const char *cmp, size_t len)
{
	size_t	o_len;
	size_t	c_len;
	size_t	size;

	if (*cmp == 0)
		return ((char *)og);
	o_len = ft_strlen(og);
	c_len = ft_strlen(cmp);
	if (len < c_len || o_len < c_len)
		return (0);
	if (len < o_len)
		size = len;
	else
		size = o_len;
	while (size-- >= c_len)
	{
		if (ft_memcmp(og, cmp, c_len) == 0)
			return ((char *)og);
		og++;
	}
	return (0);
}
