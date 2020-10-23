/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 19:50:46 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/23 11:25:47 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_nl(char *arr_save)
{
	int	i;

	i = 0;
	while (arr_save[i])
	{
		if (arr_save[i] == '\n')
			return (i);
		++i;
	}
	return (-1);
}

int	splitarray(char **sv, char **line, int idx)
{
	char	*tmp;
	int		len;

	(*sv)[idx] = 0;
	*line = ft_strdup(*sv);
	len = ft_strlen(*sv + idx + 1);
	if (!len)
	{
		free(*sv);
		*sv = 0;
		return (1);
	}
	tmp = ft_strdup(*sv + idx + 1);
	free(*sv);
	*sv = tmp;
	return (1);
}

int	ft_return(char **sv, char **line, int size)
{
	int	nl_idx;

	if (size < 0)
		return (-1);
	if (*sv && (nl_idx = is_nl(*sv)) >= 0)
		return (splitarray(sv, line, nl_idx));
	if (*sv)
	{
		*line = *sv;
		*sv = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static	char	*sv[OPEN_MAX];
	char			rd[BUFFER_SIZE + 1];
	int				size;
	int				nl_idx;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((size = read(fd, rd, BUFFER_SIZE)) > 0)
	{
		rd[size] = 0;
		sv[fd] = ft_strjoin(sv[fd], rd);
		if ((nl_idx = is_nl(sv[fd])) >= 0)
			return (splitarray(&sv[fd], line, nl_idx));
	}
	return (ft_return(&sv[fd], line, size));
}
