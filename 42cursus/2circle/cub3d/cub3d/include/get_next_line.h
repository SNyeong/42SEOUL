/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 19:32:43 by seungnle          #+#    #+#             */
/*   Updated: 2021/05/26 16:55:45 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 11999
# endif

int		get_next_line(int fd, char **line);
int		my_len(char *a);
void	my_cpy(char *s1, char *s2);
char	*my_join(char *s1, char *s2);
char	*my_dup(char *s);

#endif
