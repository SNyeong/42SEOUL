/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 07:56:16 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/16 21:53:22 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	islow(int c)
{
	return (c <= 122 && c >= 97);
}

int			ft_toupper(int c)
{
	if (islow(c))
		return (c - 32);
	return (c);
}
