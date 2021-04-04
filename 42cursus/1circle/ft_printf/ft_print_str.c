/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 07:05:01 by seungnle          #+#    #+#             */
/*   Updated: 2021/04/04 09:54:50 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_put_char_w(int width, int zero)
{
	int		count;

	count = 1;
	while (count < width)
	{
		if (zero == 1)
			ft_putchar_fd('0');
		else
			ft_putchar_fd(' ');
		count++;
	}
	return (count - 1);
}

int		ft_print_char(int c, t_option *option)
{
	int		count;

	count = 0;
	if (option->minus == 1)
		count += ft_putchar_fd(c);
	count += ft_put_char_w(option->width, option->zero);
	if (option->minus == 0)
		count += ft_putchar_fd(c);
	return (count);
}

int		ft_put_str_w(char **str, t_option *option)
{
	char	*width;
	int		i;
	int		len_w;

	if (option->width <= (int)ft_strlen(*str))
		return ((int)ft_strlen(*str));
	len_w = option->width - ft_strlen(*str);
	width = (char *)malloc(sizeof(char) * (len_w + 1));
	i = 0;
	while (i < len_w)
	{
		width[i] = (option->zero == 1) ? '0' : ' ';
		i++;
	}
	width[i] = '\0';
	if (!option->minus)
		*str = ft_strjoin(width, *str, 3);
	else
		*str = ft_strjoin(*str, width, 3);
	return (option->width);
}

char	*ft_set_str(char *str, int len)
{
	char	*temp;
	int		i;

	if (!(temp = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

int		ft_print_str(char *str, t_option *option)
{
	char	*temp;
	int		count;

	count = 0;
	if (!str)
		str = "(null)";
	if (option->precision == -1 || (size_t)option->precision > ft_strlen(str))
		option->precision = ft_strlen(str);
	temp = ft_set_str(str, option->precision);
	ft_put_str_w(&temp, option);
	count = ft_putstr_fd(temp);
	free(temp);
	return (count);
}
