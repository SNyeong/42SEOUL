/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 07:58:58 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/16 21:52:49 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	isup(int c)
{
	return (c <= 90 && c >= 65);
}

int			ft_tolower(int c)
{
	if (isup(c))
		return (c + 32);
	return (c);
}
