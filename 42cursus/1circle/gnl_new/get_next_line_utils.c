/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 14:10:23 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/23 17:32:43 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		my_len(char *a)
{
	int	i;

	i = 0;
	while (a[i])
		++i;
	return (i);
}

void	my_cpy(char *s1, char *s2)
{
	int	i;
	int	len;
	
	len = my_len(s2);
	while (i < len)
	{
		s1[i] = s2[i];
		++i;
	}
	s1[i] = 0;
}

char	*my_join(char *s1, char *s2)
{
	int		a;
	int		b;
	char	*c;
	a = my_len(s1);
	b = my_len(s2);
	c = (char *)malloc(a + b + 1);
	my_cpy(c, s1);
	free(s1);
	my_cpy(c + a, s2);
	return (c);
}

char	*my_dup(char *s)
{
	int		a;
	int		i;
	char	*c;

	a = my_len(s);
	c = (char *)malloc(a + 1);
	i = 0;
	while (i < a)
		c[i] = s[i++];
	c[i] = 0;
	return (c);
}