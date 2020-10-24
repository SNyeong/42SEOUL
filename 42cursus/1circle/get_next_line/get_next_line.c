/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 19:50:46 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/24 14:33:53 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	nl_idx(char *a)
{
	int i;

	i = 0;
	while (a[i])
	{
		if (a[i] == '\n')
			return (i);
		++i;
	}
	return (-1);
}

int	my_split(char **storage, char **line, int idx)
{
	char	*temp;

	(*storage)[idx] = 0;
	*line = my_dup(*storage);
	temp = my_dup(*storage + idx + 1);
	free(*storage);
	*storage = temp;
	return (1);
}

int	ft_return(char **storage, char **line, int size)
{
	int nl;

	if (size < 0)
		return (-1);
	if (*storage && (nl = nl_idx(*storage)) >= 0)
		return (my_split(storage, line, nl));
	if (*storage)
	{
		*line = *storage;
		*storage = 0;
		return (0);
	}
	*line = my_dup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*storage[OPEN_MAX];
	char		temp[BUFFER_SIZE + 1];
	int			nl;
	int			size;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while ((size = read(fd, temp, BUFFER_SIZE)) > 0)
	{
		temp[size] = 0;
		storage[fd] = my_join(storage[fd], temp);
		if ((nl = nl_idx(storage[fd])) >= 0)
			return (my_split(&storage[fd], line, nl));
	}
	return (ft_return(&storage[fd], line, size));
}
