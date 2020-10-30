/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:48:54 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/30 19:14:30 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

char			*ft_itoa(int n);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *ptr, int num, size_t len);

#endif
