/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 19:50:46 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/23 17:47:05 by seungnle         ###   ########.fr       */
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
	(*storage)[idx] = 0;
	*line = my_dup(*storage);
}

int	get_next_line(int fd, char **line)
{
	static char	*storage[OPEN_MAX];
	char		temp[BUFFER_SIZE + 1];
	int			nl;
	int			size;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while (size = read(fd, temp, BUFFER_SIZE) > 0)
	{
		temp[size] = 0;
		storage[fd] = my_join(storage[fd], temp);
		if (nl = nl_idx(storage[fd]) > 0)
			
	}
}
