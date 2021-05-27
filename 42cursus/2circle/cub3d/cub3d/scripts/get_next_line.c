/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 19:50:46 by seungnle          #+#    #+#             */
/*   Updated: 2021/05/27 17:55:21 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

int	ft_return(char **storage, char **line, int size)
{
	if (size < 0)
		return (-1);
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
	static char	*storage;
	char		temp[BUFFER_SIZE + 1];
	int			size;

	if (!line || BUFFER_SIZE <= 0)
		return (-1);
	while ((size = read(fd, temp, BUFFER_SIZE)) > 0)
	{
		temp[size] = 0;
		storage = my_join(storage, temp);
	}
	return (ft_return(&storage, line, size));
}
