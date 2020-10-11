/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 19:45:03 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/05 19:45:09 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int num, size_t len)
{
	unsigned char *temp;

	temp = (unsigned char *)ptr;
	while (len--)
		*temp++ = num;
	return (ptr);
}
