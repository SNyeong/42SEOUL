/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 20:56:37 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/16 21:32:57 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	size_t	len;
	int		i;

	len = ft_strlen(s1);
	if (!(ret = (char *)ft_calloc(len + 1, sizeof(char))))
		return (0);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		++i;
	}
	ret[i] = 0;
	return (ret);
}
