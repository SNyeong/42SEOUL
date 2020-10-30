/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 20:49:29 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/30 19:13:23 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	if (!(a = (void *)malloc(size * count)))
		return (0);
	ft_memset(a, 0x00, size * count);
	return (a);
}
