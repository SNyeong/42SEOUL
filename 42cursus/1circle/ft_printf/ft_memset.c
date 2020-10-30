/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 19:45:03 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/30 19:14:24 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memset(void *ptr, int num, size_t len)
{
	unsigned char *temp;

	temp = (unsigned char *)ptr;
	while (len--)
		*temp++ = num;
	return (ptr);
}
