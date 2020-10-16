/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 02:13:07 by seungnle          #+#    #+#             */
/*   Updated: 2020/10/16 20:32:47 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	if (!(ret = (t_list *)ft_calloc(1, sizeof(t_list))))
		return (0);
	ret->content = content;
	ret->next = NULL;
	return (ret);
}
