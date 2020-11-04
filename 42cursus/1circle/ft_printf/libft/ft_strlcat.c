/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 01:54:35 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/24 17:18:17 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize < dstlen + 1)
		return (dstsize + srclen);
	i = 0;
	if (dstsize > dstlen + 1)
	{
		while (src[i] != 0 && dstlen + i + 1 < dstsize)
		{
			dst[dstlen + i] = src[i];
			++i;
		}
	}
	dst[dstlen + i] = 0;
	return (dstlen + srclen);
}
