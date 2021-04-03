/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nyeong <nyeong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 22:25:13 by seungnle          #+#    #+#             */
/*   Updated: 2021/04/03 02:13:33 by nyeong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2, int type)
{
	char	*ret;
	size_t	a;
	size_t	b;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	if (!(ret = (char *)ft_calloc(sizeof(char), (a + b + 1))))
		return (0);
	ft_strlcpy(ret, s1, a + 1);
	if (type == 1 || type == 3)
		free(s1);
	ft_strlcpy(ret + a, s2, b + 1);
	if (type == 2 || type == 3)
		free(s2);
	return (ret);
}
