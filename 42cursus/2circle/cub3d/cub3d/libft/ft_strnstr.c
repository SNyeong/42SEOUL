/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 02:36:12 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/16 21:40:59 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *og, const char *cmp, size_t len)
{
	size_t	len_o;
	size_t	len_c;
	size_t	size;

	if (*cmp == 0)
		return ((char *)og);
	len_o = ft_strlen(og);
	len_c = ft_strlen(cmp);
	if (len < len_c || len_o < len_c)
		return (0);
	if (len < len_o)
		size = len;
	else
		size = len_o;
	while (size-- >= len_c)
	{
		if (ft_memcmp(og, cmp, len_c) == 0)
			return ((char *)og);
		og++;
	}
	return (0);
}
