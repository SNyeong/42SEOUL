/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:29:12 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/14 07:08:11 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	**mallocerror(char **ret)
{
	int i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		++i;
	}
	free(ret);
	return (0);
}

static	int		get_len_s(char const *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i] != c)
			cnt++;
		while (s[i] != c && s[i + 1] != 0)
		{
			++i;
		}
		++i;
	}
	return (cnt);
}

static	void	get_temp(char **s, int *len, char c)
{
	int i;

	*s = *s + *len;
	*len = 0;
	i = 0;
	while (**s && **s == c)
		++(*s);
	while ((*s)[i])
	{
		if ((*s)[i] == c)
			return ;
		++i;
		(*len)++;
	}
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	char	*temp;
	int		len_s;
	int		len_t;
	int		i;

	if (!s)
		return (0);
	len_s = get_len_s(s, c);
	if (!(ret = (char **)malloc(sizeof(char *) * len_s + 1)))
		return (0);
	if (!ret)
		return (0);
	temp = (char *)s;
	len_t = 0;
	i = 0;
	while (i < len_s)
	{
		get_temp(&temp, &len_t, c);
		if (!(ret[i] = (char *)malloc(sizeof(char) * len_t + 1)))
			return (mallocerror(ret));
		ft_strlcpy(ret[i], temp, len_t + 1);
		++i;
	}
	ret[i] = NULL;
	return (ret);
}
