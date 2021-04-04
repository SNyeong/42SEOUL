/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 07:29:59 by seungnle          #+#    #+#             */
/*   Updated: 2021/04/04 10:11:05 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_put_nb_w(char *str, t_option *option)
{
	char	*temp;
	char	c;
	int		len_w;
	int		len_nb;

	len_nb = ft_strlen(str);
	len_w = (option->width > len_nb) ? option->width - len_nb : 0;
	if (!len_w)
		return (str);
	if (!(temp = (char *)malloc(len_w + 1)))
		return (0);
	temp[len_w] = 0;
	c = (option->zero) ? '0' : ' ';
	while (len_w--)
		temp[len_w] = c;
	if (option->zero && option->sign == -1 && !option->minus)
		ft_swap(&temp[0], &str[0]);
	if (option->minus)
		return (ft_strjoin(str, temp, 3));
	return (ft_strjoin(temp, str, 3));
}

char			*ft_put_nb_sign_x(char *str, t_option *option)
{
	if (option->type == 'p')
		return (ft_strjoin("0x", str, 2));
	else if (option->sign == -1)
		return (ft_strjoin("-", str, 2));
	return (str);
}

char			*ft_put_nb_pr(char *str, t_option *option)
{
	char	*temp;
	int		len_pr;

	if (str[0] == 0 && option->precision == -1)
		return (str);
	len_pr = ft_strlen(str);
	len_pr = (option->precision > len_pr) ? option->precision - len_pr : 0;
	if (!(temp = (char *)malloc(len_pr + 1)))
		return (0);
	temp[len_pr] = 0;
	while (len_pr--)
		temp[len_pr] = '0';
	return (ft_strjoin(temp, str, 3));
}

char			*ft_set_nb(unsigned long long nb, t_option *option)
{
	char	*temp;
	int		len_nb;

	len_nb = ft_nblen(nb, option);
	if (!(temp = (char *)malloc(sizeof(char) * (len_nb + 1))))
		return (0);
	temp[len_nb] = 0;
	while (len_nb--)
	{
		temp[len_nb] = ft_base(option->type)[nb % option->base];
		nb /= option->base;
	}
	return (temp);
}

int				ft_print_nb(unsigned long long nb, t_option *option)
{
	char	*temp;
	int		count;

	if (option->type == 'x' || option->type == 'X' || option->type == 'p')
		option->base = 16;
	if ((option->type == 'd' || option->type == 'i') && (int)nb < 0)
	{
		option->sign = -1;
		nb *= -1;
	}
	temp = ft_set_nb(nb, option);
	temp = ft_put_nb_pr(temp, option);
	temp = ft_put_nb_sign_x(temp, option);
	temp = ft_put_nb_w(temp, option);
	count = ft_putstr_fd(temp);
	free(temp);
	return (count);
}
